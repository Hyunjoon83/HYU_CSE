package city;

import java.lang.Math;

public class City{
	private String name;
	private int locationX;
	private int locationY;
	
	public City(String name, int locationX, int locationY) {
		this.name=name;
		this.locationX=locationX;
		this.locationY=locationY;
	}
	public City(String name) {
		this.name=name;
		this.locationX=(int)(Math.random()*361);
		this.locationY=(int)(Math.random()*361);
	}
	public String getName() {
		return name;
	}
	public int getLocationX() {
		return locationX;
	}
	public int getLocationY() {
		return locationY;
	}
	public boolean equals(Object obj) {
		if(obj==this) {
			return true;
		}
		if(!(obj instanceof City)) {
			return false;
		}
		City otherCity=(City)obj;
		return name.equals(otherCity.getName()) && locationX==otherCity.getLocationX() && locationY==otherCity.getLocationY();		
	}
	public String toString() {
		return name+", "+locationX+", "+locationY;
	}
	public static double distance(City city1,City city2) {
		int xDist=city1.getLocationX()-city2.getLocationX();
		int yDist=city1.getLocationY()-city2.getLocationY();
			return Math.sqrt(xDist*xDist-yDist*yDist);
	}
}