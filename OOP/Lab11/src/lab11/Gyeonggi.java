package lab11;

public class Gyeonggi extends Hub{
	public static int init_num=10000;
	public static String init_Area="Gyeonggi";
	public static double init_price_per_box=3000;
	
	public Gyeonggi(String description) {
		init_num++;
		setNumber(init_num);
		setDescription(description);
        setArea(init_Area);
        setPricePerBox(init_price_per_box);
	}
	public String toString() {
		return "Box Number: "+getNumber()+"\nDescription: "+getDescription()+"\nArea: "+getArea()+"\nPrice per box: "+getPricePerBox();
	}
}
