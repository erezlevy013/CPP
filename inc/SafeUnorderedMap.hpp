#ifndef SAFE_UNORDERED_MAP_HPP
#define SAFE_UNORDERED_MAP_HPP

#include <unordered_map>
#include <shared_mutex>
#include <mutex>
#include <functional>
#include <optional>
#include <vector>
#include <thread>

namespace h72{

template <typename KEY, typename VAL>
class SafeUnorderedMap
{
public:
    explicit SafeUnorderedMap(size_t a_capacity = 1000, unsigned int a_numOfThreads = std::thread::hardware_concurrency());
    ~SafeUnorderedMap() = default;
    SafeUnorderedMap(SafeUnorderedMap const&) = delete;
    SafeUnorderedMap& operator=(SafeUnorderedMap const&) = delete;

    bool Find(KEY const& a_key) const;
    bool Contains(KEY const& a_key) const;
    bool Erase(KEY const& a_key, VAL& a_elm);
    bool Erase(KEY&& a_key, VAL& a_elm);
    
    void Set(KEY const& a_key, VAL const& a_val);
    void Set(KEY&& a_key, VAL&& a_val);
    void Update(KEY const& a_key, std::function<void(VAL&)>const& a_updater);
    void Upsert(KEY const& a_key, std::function<void(VAL&)>const& a_updater,  std::function<VAL()>& a_factory);
    void Upsert(KEY&& a_key, std::function<void(VAL&)>const& a_updater,  std::function<VAL()>&& a_factory);

    std::optional<VAL> Get(KEY const& a_key) const;
    size_t Size() const;

private:
    bool FullCapacity() const;    
    
private:
    size_t m_capacity;
    unsigned int m_numOfThreads;
    std::unordered_map<KEY,VAL> m_map;
    mutable std::vector<std::shared_mutex> m_SharedMutxs;
};

}

#include "detail/SafeUnorderedMap_inl.hxx"

#endif

