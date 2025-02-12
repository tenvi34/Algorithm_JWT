#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 문제 풀이 방식
// 1 2 3 4 5 가 있으면 새로운 리스트(역방향 리스트)에 1을 맨 처음 head로 지정, 이후 2가 들어오면 2를 다시 새로운 head로 지정
// 이런 방식으로 head가 계속 변경되면서 역방향으로 채워나간다.

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode* new_list = nullptr; // 역방향 리스트의 시작 위치
        ListNode* current = head;     // 현재 노드 (1을 가리키는 상태이지 아직 new_list에 들어가있는 상태는 아님)

        while(current)
        {
            ListNode* next_node = current->next; // current가 1일 때 current->next는 current의 다음 노드인 2를 가리킨다.
            current->next = new_list; // 1-> next = NULL
            new_list = current;
            current = next_node;
        }

        return new_list;
    }
};