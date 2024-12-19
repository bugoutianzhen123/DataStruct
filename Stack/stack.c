#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// 栈数据结构
typedef struct
{
    int top;
    double arr[MAX];
} Stack;

// 初始化栈
void init_stack(Stack *stack)
{
    stack->top = -1;
}

// 检查栈是否为空
int is_empty(Stack *stack)
{
    return stack->top == -1;
}

// 检查栈是否满
int is_full(Stack *stack)
{
    return stack->top == MAX - 1;
}

// 压栈
void push(Stack *stack, double value)
{
    if (is_full(stack))
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++(stack->top)] = value;
}

// 弹栈
double pop(Stack *stack)
{
    if (is_empty(stack))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[(stack->top)--];
}

// 获取栈顶元素
double peek(Stack *stack)
{
    if (is_empty(stack))
    {
        return -1;
    }
    return stack->arr[stack->top];
}

// 获取操作符优先级
int precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    if (op == '*' || op == '/')
    {
        return 2;
    }
    return 0;
}

// 执行操作
double apply_operator(double a, double b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        return 0;
    }
}

// 计算中缀表达式
double evaluate_infix(char *expression)
{
    Stack values, ops;
    init_stack(&values);
    init_stack(&ops);

    int i = 0;
    while (expression[i] != '\0')
    {
        char ch = expression[i];

        // 如果是空格，跳过
        if (ch == ' ')
        {
            i++;
            continue;
        }

        // 如果是数字，读取完整的数字
        if (isdigit(ch))
        {
            double value = 0;
            while (isdigit(expression[i]))
            {
                value = value * 10 + (expression[i] - '0');
                i++;
            }
            push(&values, value);
        }
        // 如果是左括号，压入操作符栈
        else if (ch == '(')
        {
            push(&ops, ch);
            i++;
        }
        // 如果是右括号，弹出直到遇到左括号
        else if (ch == ')')
        {
            while (!is_empty(&ops) && peek(&ops) != '(')
            {
                double val2 = pop(&values);
                double val1 = pop(&values);
                char op = (char)pop(&ops);
                push(&values, apply_operator(val1, val2, op));
            }
            pop(&ops); // 弹出左括号
            i++;
        }
        // 如果是操作符
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (!is_empty(&ops) && precedence(peek(&ops)) >= precedence(ch))
            {
                double val2 = pop(&values);
                double val1 = pop(&values);
                char op = (char)pop(&ops);
                push(&values, apply_operator(val1, val2, op));
            }
            push(&ops, ch);
            i++;
        }
    }

    // 处理剩余的操作符
    while (!is_empty(&ops))
    {
        double val2 = pop(&values);
        double val1 = pop(&values);
        char op = (char)pop(&ops);
        push(&values, apply_operator(val1, val2, op));
    }

    return pop(&values);
}

// 计算后缀表达式
double evaluate_postfix(char *expression)
{
    Stack stack;
    init_stack(&stack);

    int i = 0;
    while (expression[i] != '\0')
    {
        char ch = expression[i];

        // 如果是空格，跳过
        if (ch == ' ')
        {
            i++;
            continue;
        }

        // 如果是数字，读取完整的数字
        if (isdigit(ch))
        {
            double value = 0;
            while (isdigit(expression[i]))
            {
                value = value * 10 + (expression[i] - '0');
                i++;
            }
            push(&stack, value);
        }
        // 如果是操作符，弹出栈顶的两个操作数，计算并将结果压入栈
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            double val2 = pop(&stack);
            double val1 = pop(&stack);
            push(&stack, apply_operator(val1, val2, ch));
            i++;
        }
    }

    // 栈顶就是最终结果
    return pop(&stack);
}

// 计算前缀表达式
double evaluate_prefix(char *expression)
{
    Stack stack;
    init_stack(&stack);
    int len = strlen(expression);

    // 从右到左遍历前缀表达式
    for (int i = len - 1; i >= 0; i--)
    {
        char ch = expression[i];

        // 如果是空格，跳过
        if (ch == ' ')
        {
            continue;
        }

        // 如果是数字，读取完整的数字
        if (isdigit(ch))
        {
            double value = 0;
            // 读取一个完整的数字，包括可能的小数部分
            while (i >= 0 && (isdigit(expression[i]) || expression[i] == '.'))
            {
                value = value * 10 + (expression[i] - '0');
                i--;
            }
            push(&stack, value);
            i++; // 由于在循环中会减少 i，需要恢复
        }
        // 如果是操作符，弹出两个操作数并计算
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            double operand1 = pop(&stack);
            double operand2 = pop(&stack);
            double result = apply_operator(operand1, operand2, ch);
            push(&stack, result);
        }
    }

    // 栈顶的元素就是结果
    return pop(&stack);
}

int main()
{
    char expression1[] = "3 + 5 * (2 - 8)"; // 示例表达式
    printf("Result: %.2f\n", evaluate_infix(expression1));

    char expression2[] = "3 4 + 2 * 7 /"; // 示例后缀表达式
    printf("Result: %.2f\n", evaluate_postfix(expression2));

    char expression[] = "- + * 2 3 * 5 4 9"; // 示例前缀表达式
    printf("Result: %.2f\n", evaluate_prefix(expression));
    return 0;
}
