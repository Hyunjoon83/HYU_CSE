package lab11;

public class Hub {
	private int number; // 박스 serial 번호
	private String description; // 박스 객체의 설명
	private String area; // 배송 허브 위치 
	private double price_per_box; // 박스 개당 배송 단가
	
	public void setNumber(int number) {
		this.number=number;
	}
	public int getNumber() {
		return number;
	}
	public void setDescription(String description) {
		this.description=description;
	}
	public String getDescription() {
		return description;
	}
	public void setArea(String area) {
		this.area=area;
	}
	public String getArea() {
		return area;
	}
	public void setPricePerBox(double price_per_box) {
		this.price_per_box=price_per_box;
	}
	public double getPricePerBox() {
		return price_per_box;
	}
	public String toString() {
		return "Box Number: "+number+"\nDescription: "+description+"\nArea: "+area+"\nPrice per box: "+price_per_box;
	}
}
