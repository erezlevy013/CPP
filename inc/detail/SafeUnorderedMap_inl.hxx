#include <unordered_map>
#include <shared_mutex>

#include "SafeUnorderedMap.hpp"

namespace h72{

template <typename KEY, typename VAL>
SafeUnorderedMap<KEY,VAL>::SafeUnorderedMap(size_t a_capacity, unsigned int a_numOfThreads)
: m_capacity(a_capacity)
, m_numOfThreads(a_numOfThreads)
, m_map(m_capacity)
, m_SharedMutxs(a_numOfThreads)
{
}

template <typename KEY, typename VAL>
bool SafeUnorderedMap<KEY,VAL>::Find(KEY const& a_key) const
{
    size_t indx = m_map.bucket(a_key) % m_numOfThreads;
    std::shared_lock lock(m_SharedMutxs[indx]);
    auto it = m_map.find(a_key);
    if(it != m_map.end()){
        return true;
    }
    return false;
}

template <typename KEY, typename VAL>
bool SafeUnorderedMap<KEY,VAL>::Contains(KEY const& a_key) const
{
    size_t indx = m_map.bucket(a_key) % m_numOfThreads;
    std::shared_lock lock(m_SharedMutxs[indx]);
    return m_map.contains(a_key);
}

template <typename KEY, typename VAL>
bool SafeUnorderedMap<KEY,VAL>::Erase(KEY const& a_key, VAL& a_elm)
{
    size_t indx = m_map.bucket(a_key) % m_numOfThreads;
    std::unique_lock lock(m_SharedMutxs[indx]);
    if(!m_map.find(a_key)){
        return false;
    }
    a_elm = m_map[a_key];
    m_map.erase(a_key);
    return true;
}

template <typename KEY, typename VAL>
bool SafeUnorderedMap<KEY,VAL>::Erase(KEY&& a_key, VAL& a_elm)
{
    size_t indx = m_map.bucket(a_key) % m_numOfThreads;
    std::unique_lock lock(m_SharedMutxs[indx]);
    if(!m_map.find(std::move(a_key))){
        return false;
    }
    a_elm = m_map[a_key];
    m_map.erase(a_key);
    return true;
}

template <typename KEY, typename VAL>
void SafeUnorderedMap<KEY,VAL>::Set(KEY const& a_key, VAL const& a_val)
{
    size_t indx = m_map.bucket(a_key) % m_numOfThreads;
    std::unique_lock lock(m_SharedMutxs[indx]);
    if(FullCapacity()){
        throw;
    }
    auto [it, ok] = m_map.insert(std::make_pair(a_key, a_val));
    if (!ok){
        it->second = a_val;
    }
}

template <typename KEY, typename VAL>
void SafeUnorderedMap<KEY,VAL>::Set(KEY&& a_key, VAL&& a_val)
{
    size_t indx = m_map.bucket(a_key) % m_numOfThreads;
    std::unique_lock lock(m_SharedMutxs[indx]);
    if(FullCapacity()){
        throw;
    }
    auto [it, ok] = m_map.insert(std::make_pair(std::move(a_key),std::move(a_val)));
    if (!ok){
        it->second = a_val;
    }
}


template <typename KEY, typename VAL>   
void SafeUnorderedMap<KEY,VAL>::Update(KEY const& a_key, std::function<void(VAL&)>const& a_updater)
{
    size_t indx = m_map.bucket(a_key) % m_numOfThreads;
    std::unique_lock lock(m_SharedMutxs[indx]);
    auto it = m_map.find(a_key);
    if(it != m_map.end()){
        try{
            a_updater(it->second);
        }catch(...){
            throw;
        }
    }
}

template <typename KEY, typename VAL>
void SafeUnorderedMap<KEY,VAL>::Upsert(KEY const& a_key, std::function<void(VAL&)>const& a_updater,  std::function<VAL()>& a_factory)
{
    size_t indx = m_map.bucket(a_key) % m_numOfThreads;
    std::unique_lock lock(m_SharedMutxs[indx]);
    auto it = m_map.find(a_key);
    if(it != m_map.end()){
        try{
            a_updater(it->second);
        }catch(...){
            throw;
        }
    }else{
        if(FullCapacity()){
            throw;
        }

        try{
            m_map.insert(std::make_pair(a_key, a_factory()));
        }catch(...){
            throw;
        }
    }
}

template <typename KEY, typename VAL>
void SafeUnorderedMap<KEY,VAL>::Upsert(KEY&& a_key, std::function<void(VAL&)>const& a_updater,  std::function<VAL()>&& a_factory)
{
    size_t indx = m_map.bucket(a_key) % m_numOfThreads;
    std::unique_lock lock(m_SharedMutxs[indx]);
    auto it = m_map.find(std::move(a_key));
    if(it != m_map.end()){
        try{
            a_updater(it->second);
        }catch(...){
            throw;
        }
    }else{
        if(FullCapacity()){
            throw;
        }

        try{
            m_map.insert(std::make_pair(a_key, a_factory()));
        }catch(...){
            throw;
        }
    }
}

template <typename KEY, typename VAL>
std::optional<VAL> SafeUnorderedMap<KEY,VAL>::Get(KEY const& a_key) const
{
    size_t indx = m_map.bucket(a_key) % m_numOfThreads;
    std::shared_lock lock(m_SharedMutxs[indx]);
    auto it = m_map.find(a_key);
    if(it != m_map.end()){
        return it->second;
    }
    return {};
}

template <typename KEY, typename VAL>
size_t SafeUnorderedMap<KEY,VAL>::Size() const
{
    std::shared_lock lock(m_SharedMutxs[0]);
    return m_map.size();
}

template <typename KEY, typename VAL>
bool SafeUnorderedMap<KEY,VAL>::FullCapacity() const
{
    return (m_map.max_bucket_count() * 0.75 < m_map.size() + 1);
}

}

