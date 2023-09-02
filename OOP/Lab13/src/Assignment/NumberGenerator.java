package Assignment;

import java.util.ArrayList;

public abstract class NumberGenerator {
	private ArrayList<Observer> observers=new ArrayList<Observer>();//Observer형을 갖는 observers ArrayList 생성
	
	public abstract int getNumber();//getNumber 추상메서드
	public abstract void execute();//execute 추상메서드
	
	public void addObserver(Observer observer) {
		observers.add(observer);
	}//observers ArrayList에 observer를 추가하는 addObserver 메서드
	public void deleteObserver(Observer observer) {
		observers.remove(observer);
	}//observers ArrayList애서 observer를 제거하는 deleteObserver 메서드
	public void notifyObservers() {
		for(int i=0;i<observers.size();i++) {
			observers.get(i).update(this);
		}//number값이 바뀔 때마다 observers에서 자기 자신을 update
	}
}
