package lab11;

import java.lang.reflect.Field;
import java.util.ArrayList;
import java.lang.reflect.*;
import java.io.*;

public class ServiceManagement {
	public static <T extends Hub> int findIndexByNum(ArrayList<T> tList, int num) {
		for(int i=0;i<tList.size();i++) {
			if(tList.get(i).getNumber()==num)
				return i;
		}
		return -1;
	}
	public static <T extends Hub> T raisePerBox(T t,double rate) {
		double currentPrice=t.getPricePerBox();
		double newPrice=currentPrice*rate;
		t.setPricePerBox(newPrice);
		return t;
	}
	public static <T extends Hub> ArrayList<T> raiseAll(Class<T> c, ArrayList<T> tList, double rate){
		for(T elem:tList) {
			elem.setPricePerBox(rate*elem.getPricePerBox());
		}
		try {
			Field f=c.getField("init_price_per_box");
			double value=f.getDouble(null);
			f.setDouble(null, value*rate);
		}catch(NoSuchFieldException | SecurityException | IllegalArgumentException | IllegalAccessException e) {
			e.printStackTrace();	
		}
		return tList;
	}
	public static <T extends Hub> void packageBoxes(String[] descriptions, Class<T> classtype, ArrayList<T> tList) {
		try {
			for (String description : descriptions) {
	            Constructor<T> constructor = classtype.getConstructor(String.class);
	            T hubInstance = constructor.newInstance(description);
	            tList.add(hubInstance);
	        }
		}catch (NoSuchMethodException | IllegalAccessException | InvocationTargetException | InstantiationException e) {
	        e.printStackTrace();
		}
	}
	public static <T extends Hub, U extends Hub> void changeHub(ArrayList<T> tList, int index, Class<U> classtype, ArrayList<U> uList){
		try {
			T object=tList.get(index);
			String description=object.getDescription();
			Constructor<U> constructor=classtype.getConstructor(String.class);
			U newObject = constructor.newInstance(description);
			tList.set(index, null);
			double originalPrice = newObject.getPricePerBox();
	        double discountedPrice = originalPrice*0.9;
	        newObject.setPricePerBox(discountedPrice);
			uList.add(newObject);
		}catch (NoSuchMethodException | IllegalAccessException | InvocationTargetException | InstantiationException e) {
	        e.printStackTrace();
		}
	}
}
