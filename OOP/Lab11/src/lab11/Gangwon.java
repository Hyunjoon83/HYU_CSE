package lab11;

public class Gangwon extends Hub{
	public static int init_num=20000;
	public static String init_Area="Gangwon";
	public static double init_price_per_box=4000;
	
	public Gangwon(String description) {
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
