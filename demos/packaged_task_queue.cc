#include <thread>

std::queue<std::function<void()>> tasks;

template<typename F, typename... Args>
auto enqueue(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>>::type {
  using ret_type = typename std::result_of<F(Args...)>::type;
  auto task = std::make_shared<std::packaged_task<ret_type>()>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
  std::future<ret_type> res = task->get_future();

  tasks.emplace([task]() { (*task)(); });
}