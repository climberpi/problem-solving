#include<cstdio>
#include<cstring>

const int MAXn = 100000 + 5;

struct ListNode { char ch; ListNode* next; };

ListNode s[MAXn], *next, *front, *rear, *InsPos;

int main() {
    while(1) {
        char ch;
        next = s + 1; 
        front = s;
        front -> next = NULL;
        rear = front;
        InsPos = rear;
        while(1) {
            ch = getchar();
            if(ch == '\n') break;
            if(ch == EOF) return 0;

            if(ch == '[') InsPos = front;
            else if(ch == ']') InsPos = rear;
            else {
                ListNode* Node = ++next;
                Node->ch = ch;
                Node->next = InsPos->next;

                InsPos->next = Node;
                InsPos = Node;
                if(rear->next != NULL) rear = InsPos;
            }
        }

        ListNode* cur = front->next;
        do { putchar(cur->ch); } while((cur = cur->next) && cur != NULL);
        putchar('\n');
    }
    return 0;
}
