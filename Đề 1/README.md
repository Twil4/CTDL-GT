# Câu 1:
- Phép tích cực: Là phép toán mà thuộc giải thuật mà thời gian thực hiện nó không ít hơn thời gian thực hiện các phép toán khác, hay số lần thực hiện nó không kém gì cách thực hiện nó

- Quy tắc tổng: Giả sử T1(n) và T2(n) là thời gian thực hiện của 2 đoạn chương trình P1 và P2 mà T1(n) = O(f(n)); T2(n) = O(g(n)) thì thời gian thực hiện P1 và P2 kế tiếp nhau sẽ là: T1(n) + T2(n) = O(max(f(n), g(n))).

- Ví dụ: 1 chương trình có 3 bước thực hiện mà thời gian thực hiện từng bước là: O(n2), O(n3) và O(nlog2n) thì thời gian thực hiện 2 bước đầu là O(max(n2, n3)) = O(n3). Thời gian thực hiện chương trình sẽ là: O(max(n3, nlog2n)) = O(n3).

- Quy tắc nhân: Nếu tương ứng với P1, P2 là T1(n) = O(f(n)), T2(n) = O(g(n)) thì thời gian thực hiện P1 và P2 lồng nhau sẽ là: T1(n)T2(n) = O(f(n)g(n)).

- Ví dụ: Cho câu lệnh gán x := x + 1 có thời gian thực hiện bằng c(hằng số) nên được đánh giá là O(1)

Câu lệnh for i := 1 to n do x := x + 1 có thời gian thực hiện O(n.1) = O(n)

# Câu 2: a,

- Duyệt trước: A -> C -> G -> F -> B -> E -> I -> D -> H

- Duyệt giữa: G -> C -> F -> A -> I -> E -> B -> D -> H

- Duyệt sau: G -> F -> C -> I -> E -> H -> D -> B -> A

# Câu 2: b, 5, 2, 26, 7, 4, 25, 9

- Chọn chốt là 5:
+ i = 2 < 5 => i = 26 > 5 -> Dừng
+ j = 9 < 5.
+ Vì i > j => Đổi chỗ 26 với 9 ta được chuỗi sau: ***5  2  9  7  4  25 26***. 9 > 5 => Dừng

- Tiếp tục lặp lại
+ i = 2 < 5 => i = 9 > 5
+ j = 26 > 5 => j = 25 => 5 => j = 4 < 5
+ Vì i > j => Đổi chỗ 9 và 4 ta được chuỗi sau: ***5  2  4  7  9  25  26***
+ Vì j = 4 < 5 nên đổi chỗ cho chốt 5 ta được chuỗi sau: ***4  2  5  7  9  25  26***

- Tiếp tục lặp lại
+ i = 2 < 4 => i = 5 > 4
+ j = 26 > 4 => j = 25 > 4 => j = 9 > 4 => j = 7 > 4 => j = 5 > 4 => j = 2 < 4
+ Vì i = j = 2 < 4 (chốt) nên đổi chỗ với chốt ta được chuỗi sau: ***2  4  5  7  9  25  26***

# Câu 2: c,

![](/Đề%201/2c.png)

# Câu 3: 
- Thuật toán tựa C như sau: 
```
Ý tưởng:
- Tạo 1 stack rỗng
- Đọc lần lượt các phần tử từ trái qua phải
    + Nếu là toán hạng thì đẩy vào stack
    + Nếu là toán tử thì lấy từ stack 2 giá trị (Y và Z) sau đó áp dụng toán tử với 2 giá trị vừa lấy ra, đẩy kết quả tìm được (Z X Y) vào stack
- Sau khi kết thúc bước trên thì giá trị trong stack là giá trị biểu thức
```

```c
double caculate(){
    //Giải thuật sử dụng stack S, con trỏ T bắt đầu là -1
    do{
        Đọc phần tử X tiếp theo của con trỏ
        if X là toán hạng {
            PUSH(S, T, X);
        }else {
            Y = POP(S, T);
            Z = POP(S, T);
            W = Z X Y; //Thực hiện phép tính X
            PUSH(S, T, X);
        }
    }while(Gặp ký tự '\0');
    R = POP(S, T);
    printf(R);
}
```

- Code chi tiết có thể xem tại [đây](/Đề%201/cau3.c)

![](/Đề%201/c4.png)

# Câu 5: 
```
Ý tưởng:
- Tìm kiếm X xem có trên cây không. Nếu tìm thấy thì trỏ P vào nút cần xóa
    + Nếu P là nút lá thì chỉ cần đem mối nối cũ trỏ tới node P (node cha của P) trỏ về null và giải phóng P
    + Nếu P là nút nửa lá (chỉ có 1 nhánh trái hoặc nhánh phải) thì nút thay thế P là nút gốc của nhánh con đó. Khi đó ta điều chỉnh mối nối như sau: Mối nối trỏ tới P (nút cha của P) trỏ tới nút gốc của nhánh con của P, sau đó giải phóng P
    + Nếu P là nút có đầy đủ 2 nhánh thì nút thay thế P là nút lớn nhất thuộc cây con trái hoặc nút bé nhất của cây con phải. Khi đó thay vì xóa nút P thì lấy giá trị của nút thay thế thay vào giá trị nút P rồi xóa nút thây thế
```

- Code tựa C như sau:
```c
XOA_NUT(T, P){
    P = T;Q = NULL; //Vể sau P trỏ sang nút khác, Q luôn giữ là nút cha của P
    //Kiểm tra X có trong cây T không
    while(P != NULL){
        if(P->KEY == X){ //Tìm thấy X
            break;
        }
        Q = P; // Luôn giữ Q là nút cha của P
        if(x < P->KEY){
            P = P->P_L;
        }else{
            P = P->P_R;
        }
    }
    //Nếu X không được tìm thấy
    if(P = NULL){
        break;
    }
    //P có đầy đủ 2 nhánh
    if(P->P_L != NULL && P->P_R != NULL){
        //Tìm nút cực phải của cây con trái làm nút thay thế
        Node = P; //Ghi nhớ nút cần xóa
        Q = P; P = P->P_L; //Chuyển sang cây con trái tìm nút lớn nhất
        while(P->P_R != NULL){
            Q = P;
            P = P->P_R;
        }
        Node->KEY = P->KEY; //Chuyển key lên nút cần xóa
    }
    //Nút bây giờ cần xóa là nút P có 1 nhánh hoặc không có gì. Xử lý như này sẽ xử lý luôn 2 th kia
    if(P->P_L != NULL){
        Child = P->P_L;
    }else {
        Child = P->P_R;
    }
    if(P == T){
        T = Child;
    }else {
        if(Q->P_L == P){
            Q->P_L = Child;
        }else {
            Q->P_R = Child;
        }
    }
    free(P);
}
```