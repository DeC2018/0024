#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    const int length = getLength(head);
    ListNode dummy(0, head);
    ListNode* prev = &dummy;
    ListNode* curr = head;

    for (int i = 0; i < length / 2; ++i) {
      ListNode* next = curr->next;
      curr->next = next->next;
      next->next = prev->next;
      prev->next = next;
      prev = curr;
      curr = curr->next;
    }

    return dummy.next;
  }

 private:
  int getLength(ListNode* head) {
    int length = 0;
    for (ListNode* curr = head; curr; curr = curr->next)
      ++length;
    return length;
  }
};

vector<int> convertListToArray(ListNode* head) {
    vector<int> result;
    ListNode* temp = head;
    while (temp != nullptr) {
        result.push_back(temp->val);
        temp = temp->next;
    }
    return result;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution solution;
    ListNode* result = solution.swapPairs(head);

    // Convert the linked list to array for easier printing
    vector<int> resultArray = convertListToArray(result);

    // Print the result in the desired format
    cout << "[";
    for (int i = 0; i < resultArray.size(); ++i) {
        cout << resultArray[i];
        if (i < resultArray.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    // Clean up the memory
    while (result != nullptr) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}