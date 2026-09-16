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
