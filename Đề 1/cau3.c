#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100 //Khai báo kích thước tối đa của stack

//Khai báo cấu trúc của stack
typedef struct
{
    int top;
    double items[MAX_STACK_SIZE];
} Stack;

// Khởi tạo stack
void init(Stack* stack){
    stack->top = -1;
}

// Kiểm tra xem stack có rỗng không
int isEmpty(Stack* stack){
    if(stack->top == -1) return 1;
    return 0;
}

// Kiểm tra xem stack có đầy không
int isFull(Stack* stack){
    if(stack->top == MAX_STACK_SIZE - 1) return 1;
    return 0;
}

// Đẩy giá trị vào stack
void Push(Stack* stack, double value){
    if(isFull(stack)) {
        printf("Stack day\n");
        return;
    }
    stack->items[++stack->top] = value;
}

//Lấy giá trị ra khỏi stack
double Pop(Stack* stack){
    if(isEmpty(stack)){
        printf("Stack rong\n");
        return 0;
    }
    return stack->items[stack->top--];
}

//Tính toán
double calculate(char* expression) {
    Stack stack;
    init(&stack);
    double value1, value2;

    //Duyệt từ đầu chuỗi đến cuối chuỗi
    for (int i = 0; expression[i] != '\0'; i++){
        if(isdigit(expression[i])){ //Nếu ký tự là số thì Push vào stack
            Push(&stack, (double)(expression[i] - '0'));
        }else if(expression[i] == ' '){ // Nếu ký tự là dấu cách thì bỏ qua
            continue;
        }else{
            value1 = Pop(&stack); //Lấy giá trị ra khỏi stack
            value2 = Pop(&stack); //Lấy giá trị ra khỏi stack
            switch(expression[i]){
                //Check từng toán tử -> Tính toán rồi thêm vào stack
                case '+':
                    Push(&stack, value1+value2);
                    break;
                case '-':
                    Push(&stack, value2-value1);
                    break;
                case '*':
                    Push(&stack, value1*value2);
                    break;
                case '/':
                    Push(&stack, value2/value1);
                    break;
                default:
                    printf("Toan tu khong hop le\n");
                    return 0;
            }
        }
    }
    //Trả về kết quả cuối cùngs
    return Pop(&stack);
}

int main(){
    char expression[] = "9 5 - 6 2 / +";
    double result = calculate(expression);
    printf("Ket qua: %.2f\n", result);

    return 0;
}