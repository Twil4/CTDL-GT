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
