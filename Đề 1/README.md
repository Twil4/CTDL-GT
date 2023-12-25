# Câu 1:
- Phép tích cực: Là phép toán mà thuộc giải thuật mà thời gian thực hiện nó không ít hơn thời gian thực hiện các phép toán khác, hay số lần thực hiện nó không kém gì cách thực hiện nó

- Quy tắc tổng: Giả sử T1(n) và T2(n) là thời gian thực hiện của 2 đoạn chương trình P1 và P2 mà T1(n) = O(f(n)); T2(n) = O(g(n)) thì thời gian thực hiện P1 và P2 kế tiếp nhau sẽ là: T1(n) + T2(n) = O(max(f(n), g(n))).

Ví dụ: 1 chương trình có 3 bước thực hiện mà thời gian thực hiện từng bước là: O(n2), O(n3) và O(nlog2n) thì thời gian thực hiện 2 bước đầu là O(max(n2, n3)) = O(n3). Thời gian thực hiện chương trình sẽ là: O(max(n3, nlog2n)) = O(n3).

- Quy tắc nhân: Nếu tương ứng với P1, P2 là T1(n) = O(f(n)), T2(n) = O(g(n)) thì thời gian thực hiện P1 và P2 lồng nhau sẽ là: T1(n)T2(n) = O(f(n)g(n)).

- Ví dụ: Cho câu lệnh gán x := x + 1 có thời gian thực hiện bằng c(hằng số) nên được đánh giá là O(1)

Câu lệnh for i := 1 to n do x := x + 1 có thời gian thực hiện O(n.1) = O(n)

# Câu 2: a,

- Duyệt trước: A -> C -> G -> F -> B -> E -> I -> D -> H

- Duyệt giữa: G -> C -> F -> A -> I -> E -> B -> D -> H

- Duyệt sau: G -> F -> C -> I -> E -> H -> D -> B -> A

