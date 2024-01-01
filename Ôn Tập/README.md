# Thêm 1 nút P có giá trị X trước nút Q trong dslk đôi

Ý tưởng:
- Tạo nút cần thêm (P)
- Kiểm tra có rỗng không? Nếu có thì gán đầu cuối cho P
- Kiểm tra xem nút đầu có phải nút gốc không? Nếu có thì thêm P trước nó
- Trường hợp còn lại là 1 trong những nút còn lại

```c
THEMNUT(Pdau, Pcuoi, Q, X){
    //Tạo nút P
    P = MALLOC();
    P->DATA = X;
    P->P_L = P->P_R = NULL;

    // Kiểm tra danh sách có rỗng không
    if(Pcuoi == NULL){
        Pdau = Pcuoi = P;
    }else {
        // Kiểm tra đầu danh sách bằng Q không
        if(Pdau == Q){
            Q->P_L = p;
            P->P_R = Q;
            Pdau = P;
        }else {
            // Xử lý nếu nút gốc không phải đầu
            P->P_L = Q->P_L;
            P->P_R = Q;
            Q->P_L = P;
            P->P_L->P_R = P;
        }
    }
}
```