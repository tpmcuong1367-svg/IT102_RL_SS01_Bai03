# include <stdio.h>

int main(void){
	int order_id;
	int subtotal;
	float distance_km;
	int booking_hour;
	int is_store_open;
	int inventory_qty; 
	
	printf ("Nhap ma don hang : ");
	scanf("%d",&order_id);
	
	printf("Nhap gia tri tien mon an (VND):");
	scanf("%d",&subtotal);
	
	printf("Nhap gio dat hang (km):");
	scanf("%d",&distance_km);
	
	printf("Nhap gio dat hang (0-23):");
	scanf("%d",&booking_hour);
	
	printf("Nhap trang thai quan mo cua (1:Mo,0:Dong):");
	scanf("%d",&is_store_open);
	
	printf("Nhap so luong ton kho : ");
	scanf("%d",&inventory_qty);
	
	int is_valid_input = (subtotal>0)&&(distance_km>0.0f) && (booking_hour>=0 && booking_hour <=23);
	int is_valid_order = is_valid_input && (is_store_open ==1) &&(inventory_qty > 0) &&(distance_km<=15.0f);
	
	int is_peak_hour = ((booking_hour>=11 && booking_hour<=13)||(booking_hour>=18 && booking_hour<=20));
	int is_discount_eligible = (subtotal>=100000);
	
	int base_fee = 15000;
	int surcharge = is_peak_hour * 10000;
	int discount = is_discount_eligible * 15000;
	
	int final_delivery_fee = (base_fee + surcharge-discount) * is_valid_order;
	
	 int total_payment = (subtotal + final_delivery_fee) * is_valid_order;

    printf("\n==================================================\n");
    printf("          SHOPEEFOOD ORDER CHECKOUT RECEIPT       \n");
    printf("==================================================\n");
    printf("Ma don hang         : %d\n", order_id);
    printf("Tien mon an         : %d VND\n", subtotal);
    printf("Khoang cach giao    : %.1f km\n", distance_km);
    printf("Gio dat hang        : %dh\n", booking_hour);
    printf("Trang thai quan     : %d (1: Mo, 0: Dong)\n", is_store_open);
    printf("So luong ton kho    : %d\n", inventory_qty);
    printf("--------------------------------------------------\n");
    printf("Cuoc phi co ban     : %d VND\n", base_fee);
    printf("Phu phi cao diem    : %d VND\n", surcharge);
    printf("Giam gia ship       : -%d VND\n", discount);
    printf("Phi ship thuc te    : %d VND\n", final_delivery_fee);
    printf("--------------------------------------------------\n");
    printf("TRANG THAI DON HANG : %d (1: HOP LE / 0: TU CHOI)\n", is_valid_order);
    printf("TONG THANH TOAN     : %d VND\n", total_payment);
    printf("==================================================\n");

    return 0;
} 
