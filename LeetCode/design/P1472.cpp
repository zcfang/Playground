#include <string>
#include <vector>
#include <assert.h>

class BrowserHistory {
public:
    std::vector<std::string> history;
    int current_page;
    /**
     * Problem from LeetCode 1472: Design Browser History. You can find the
     * problem
     * <a href="https://leetcode.com/problems/design-browser-history/">
     * here</a>.
     *
     * @param[in] homepage: Initializes the object with the homepage of the
     * browser.
     */
    BrowserHistory(std::string homepage) {
        history.push_back(homepage);
        current_page = 0;
    }
    
    /**
     * Visits url from the current page. It clears up all the forward history.
     *
     * @param[in] url: Website to visit
     */
    void visit(std::string url) {
        if (current_page == history.size() - 1) {
            history.push_back(url);
            current_page++;
        } else {
            int remove = history.size() - current_page - 1;

            for (int i = 0; i < remove; i++) {
                history.pop_back();
            }
            history.push_back(url);
            current_page++;
        }
    }

    /**
     * Move `steps` back in history. If you can only return x steps in the
     * history and `steps` > x, you will return only x steps. Return the
     * current URL after moving back in history at most `steps`.
     *
     * @param[in] steps: Steps to move back in history
     * @returns The current URL after moving back in history at most `steps`.
     */
    std::string back(int steps) {
        current_page = steps > current_page ? 0 : current_page - steps;

        return history[current_page];
    }

    /**
     * Move `steps` forward in history. If you can only forward x steps in the
     * history and `steps` > x, you will forward only x steps.
     *
     * @param[in] steps: Steps to move forward in history
     * @returns The current URL after forwarding in history at most `steps`.
     */
    std::string forward(int steps) {
        if (steps > (history.size() - current_page - 1)) {
            current_page = history.size() - 1;
        } else {
            current_page += steps;
        }

        return history[current_page];
    }
};

int main(int argc, char const *argv[]) {
    BrowserHistory *browser_history = new BrowserHistory("leetcode.com");

    browser_history->visit("google.com");
    browser_history->visit("facebook.com");
    browser_history->visit("youtube.com");
    assert(browser_history->back(1) == "facebook.com");

    return 0;
}
