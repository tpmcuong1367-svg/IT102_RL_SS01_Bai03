BÁO CÁO PHÂN TÍCH TRADE-OFF & THIẾT KẾ MODULE CHECKOUT SHOPEEFOOD
1. Phân tích bài toán (I/O Specification)
Input
order_id (int): Mã số định danh đơn hàng.
subtotal (int): Tiền món ăn gốc (VNĐ).
distance_km (float): Khoảng cách giao nhận (km).
booking_hour (int): Giờ đặt hàng (0 - 23).
is_store_open (int): Trạng thái quán (1: Mở, 0: Đóng).
inventory_qty (int): Số lượng món khả dụng trong kho.
Output
final_delivery_fee (int): Cước phí giao hàng thực tế sau ưu đãi và phụ phí.
is_valid_order (int): Trạng thái phê duyệt đơn (1: Hợp lệ, 0: Từ chối).
total_payment (int): Tổng tiền thanh toán cuối cùng của khách hàng.
2. Đề xuất 02 giải pháp kỹ thuật
Giải pháp A (Tách biệt cờ hiệu - Flag-based Arithmetic): Phân rã từng ràng buộc thành các biến cờ nguyên (is_valid_input, is_valid_order, is_peak_hour, is_discount_eligible). Giá trị các biến này nhận 0 hoặc 1, sau đó nhân trực tiếp với số tiền để tính cước.
Giải pháp B (Gộp biểu thức logic đơn - Single-Expression Inline): Gộp toàn bộ điều kiện logic vào thẳng công thức tính total_payment và final_delivery_fee chỉ trong một dòng lệnh duy nhất mà không khai báo biến phụ.
3. Bảng so sánh Trade-off giữa hai giải pháp
Tiêu chí	Giải pháp A (Biến cờ phân rã)	Giải pháp B (Biểu thức gộp inline)
Độ đọc hiểu (Readability)	Rất cao: Từng biến mang tên nghiệp vụ rõ ràng, theo sát tư duy đọc code logic.	Rất thấp: Biểu thức dài, nhiều tầng dấu ngoặc (), dễ gây hoa mắt.
Khả năng bảo trì (Maintainability)	Dễ dàng: Thay đổi khung giờ cao điểm hay ngưỡng Freeship chỉ cần sửa đúng 1 biến cờ.	Khó khăn: Nguy cơ sửa sót hoặc làm vỡ cấu trúc ngoặc logic khi sửa đổi.
Nguy cơ lỗi tiềm ẩn (Bug-proneness)	Rất thấp: Dễ cô lập và in debug giá trị từng cờ xem sai ở khâu nào.	Rất cao: Cực khó đặt điểm debug; nhầm lẫn giữa && và `
Dung lượng bộ nhớ (Memory)	Chiếm thêm khoảng 16 - 24 bytes bộ nhớ Stack cho biến cờ trung gian.	Tối ưu hơn: Không tốn bộ nhớ lưu biến trung gian.
Kết luận lựa chọn
Chọn Giải pháp A. Trong hệ thống Backend thực tế của ShopeeFood, mức tiêu hao vài chục bytes bộ nhớ là không đáng kể so với lợi ích về tính minh bạch, khả năng bảo trì và tốc độ truy vết lỗi nghiệp vụ.

4. Bảng kiểm thử đối chứng kịch bản ngoại lệ (Defensive Edge Cases)
Kịch bản	Dữ liệu đầu vào	is_valid_order	total_payment	Giải thích nghiệp vụ
Đơn chuẩn cao điểm	Subtotal: 120000, Km: 3.0, Giờ: 12, Quán: 1, Kho: 5	1	130000 VND	Đạt freeship (-15k), cao điểm trưa (+10k) 
→
 Ship = 10k.
Giờ đặt dị biệt (< 0)	Subtotal: 80000, Km: 2.0, Giờ: -2, Quán: 1, Kho: 2	0	0 VND	Giờ đặt không hợp lệ 
→
 Chặn đơn tự động về 0đ.
Giao quá xa (> 15km)	Subtotal: 200000, Km: 16.5, Giờ: 19, Quán: 1, Kho: 10	0	0 VND	Vượt bán kính giao hàng tối đa 15km 
→
 Hủy đơn.
Kho hết hàng	Subtotal: 50000, Km: 1.0, Giờ: 8, Quán: 1, Kho: 0	0	0 VND	Tồn kho bằng 0 
→
 Vô hiệu hóa hóa đơn.
Tiền món âm	Subtotal: -50000, Km: 2.0, Giờ: 10, Quán: 1, Kho: 5	0	0 VND	Dữ liệu đầu vào sai lệch 
→
 Bị triệt tiêu về 0đ.
