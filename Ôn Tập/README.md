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

# Loại bỏ nút Q trong danh sách

Ý tưởng:
- Kiểm tra danh sách có null không? Null thì dừng
- Kiểm tra nút xóa phải nút đầu tiên không. Nếu đúng thì thay đổi Pdau = Q->P_R
- Kiểm tra nút xóa phải nút cuối cùng không. Nếu đúng thì Pcuoi = Q->P_L
- Trường hợp còn lại là một tỏng những nút còn lại

```c
XOA_NUT(Pdau, Pcuoi, Q){
    if(Pcuoi == NULL){
        print("Danh sach rong");
    }else {
        if(Q == Pdau){
            Pdau = Q->P_R;
            Pdau->P_L = NULL;
        }else if(Q == Pcuoi){
            Pcuoi = Q->P_L;
            Pcuoi->P_R = NULL;
        }else {
            Q->P_L->P_R = Q->P_R;
            Q->P_R->P_L = Q->L;
        }
    }
}
```