#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;

typedef struct  stackNode {
    element data;
    struct stackNode* link;
} stackNode;

stackNode* top;


int isEmpty() {
    if (top == NULL) return 1;
    else return 0;
}

void topMakeNull()
{
    stackNode* temp;
    while (top != NULL)
    {
        temp = top;
        top = top->link;
        free(temp);
    }
}

void push(element item) {
    stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
    temp->data = item;
    temp->link = top;
    top = temp;
}


element pop() {
    element item;
    stackNode* temp = top;

    if (top == NULL) {
        printf("\n\n Stack is empty !\n");
        return 0;
    }
    else {
        item = temp->data;
        top = temp->link;
        free(temp);
        return item;
    }
}


int testPair(char* exp) {

    topMakeNull();
    char symbol, open_pair;

    int i, length = strlen(exp);
    top = NULL;

    for (i = 0; i < length; i++) {
        symbol = exp[i];
        switch (symbol) {

        case '(':
        case '[':
        case '{':
            push(symbol); break;

        case ')':
        case ']':
        case '}':
            if (top == NULL) return 0;
            else {

                open_pair = pop();

                if ((open_pair == '(' && symbol != ')') ||
                    (open_pair == '[' && symbol != ']') ||
                    (open_pair == '{' && symbol != '}'))

                    return 0;

                else break;
            }
        }
    }
    if (top == NULL) return 1;
    else return 0;
}

char* changeFormBack(char* exp)
{
    topMakeNull();
    char symbol;
    int length = strlen(exp), count = 0;
    char* changeValue = (char*)malloc(sizeof(char) * length);
    memset(changeValue, '\0', length);
    for (int i = 0; i < length; i++)
    {
        symbol = exp[i];
        if ('0' <= symbol && symbol <= '9')
        {
            changeValue[count++] = symbol;
            continue;
        }
        switch (symbol) {
        case '+':
        case '-':
        case '*':
        case '/':
            push(symbol); break;
        case ')':
        case '}':
        case ']':
            changeValue[count++] = pop();
            break;

        }

    }
    return changeValue;
}


element evalPostfix(char* exp) {
    topMakeNull();
    int opr1, opr2, value, i = 0;

    int length = strlen(exp);
    char symbol;
    top = NULL;

    for (i = 0; i < length; i++) {
        symbol = exp[i];
        if (symbol >= '0' && symbol <= '9') {
            value = symbol - '0';
            push(value);
        }
        else {
            opr2 = pop();
            opr1 = pop();

            switch (symbol) {
            case '+': push(opr1 + opr2); break;
            case '-': push(opr1 - opr2); break;
            case '*': push(opr1 * opr2); break;
            case '/': push(opr1 / opr2); break;
            }
        }
    }

    return pop();
}





int main(void) {
    char* exp;
    char express[100];
    int result;

    printf("수식을 입력해주세요. ex) { (3 * 5) - (6 / 2) }\n");
    gets_s(express, 100);


    if (testPair(express) == 1)
        printf("\n\n수식의 괄호가 맞게 사용되었습니다!");
    else
        printf("\n\n수식의 괄호가 틀렸습니다!");


    exp = changeFormBack(express);
    printf("\n\n후위 연산자로 바꾼값-> %s", exp);

    result = evalPostfix(exp);
    printf("\n\n연산 결과 => %d", result);

    return 0;
}
