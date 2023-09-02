package city;

public class CityTest {
	
	public static void main(String[] args) {
		City seoul = new City("Seoul",23,45);
		City paris = new City("Paris",123,41);
		City racoonCity = new City("Racoon City");
		City megaCity = new City("Mega City");			
		
		System.out.println(seoul);
		System.out.println(paris);
		System.out.println(racoonCity);
		System.out.println(megaCity);
		
		System.out.println("Seoul-Paris: " + City.distance(seoul,paris));
		System.out.println("Seoul-Racoon City: " + City.distance(seoul,racoonCity));
		System.out.println("Paris-Mega City: " + City.distance(paris,megaCity));
	}
}
