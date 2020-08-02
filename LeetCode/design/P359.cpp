#include <unordered_map>
#include <string>
#include <assert.h>

class Logger {
public:
    std::unordered_map<std::string, int> log;
    /**
     * Problem from LeetCode 1472: Logger Rate Limiter. You can find the
     * problem
     * <a href="https://leetcode.com/problems/logger-rate-limiter/">
     * here</a>.
     */
    Logger() {
        
    }
    
    /**
     * If this method returns false, the message will not be printed. The
     * timestamp is in seconds granularity.
     *
     * @returns Returns true if the message should be printed in the given
     * timestamp, otherwise returns false. 
     */
    bool should_print_message(int timestamp, std::string message) {
        if (!log.count(message) || timestamp - log[message] >= 10) {
            log[message] = timestamp;
            return true;
        }

        return false;
    }
};

int main(int argc, char const *argv[]) {
    Logger *logger = new Logger();

    assert(logger->should_print_message(1, "foo"));
    assert(logger->should_print_message(2,"bar"));
    assert(!logger->should_print_message(3,"foo"));

    return 0;
}
