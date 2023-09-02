package lab08;

import java.time.LocalDate;

public class ICE extends Car{
	private static int carNum;
	private static int CO2emission;
	private static final int GFGPERCAR=35;
	
	public ICE() {
		super();
		this.name=name;
		this.date=date;
	}
	public ICE(String name,LocalDate date,int carNum) {
		super();
		this.name=name;
		this.date=date;
		this.carNum += carNum;
		this.CO2emission += carNum * GFGPERCAR;
	}
	public boolean equals(Object obj) {
	    if (obj instanceof ICE) {
	        ICE other = (ICE) obj;
	        return (this.name.equals(other.name) && this.date.equals(other.date));
	    }
	    return false;
	}
	public String toString() {
		return String.format("name: %s, date: %s, carNum: %d",this.name,this.date,this.carNum);
	}
	public int totalCO2() {
        System.out.println("ICE emits CO2 most when driving");
        return this.CO2emission;
    }
	
}
