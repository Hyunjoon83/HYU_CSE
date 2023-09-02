package Assignment;

public class Buffer {
	private int loc=0;
	private double[] data;
	//loc를 0으로 초기화하고 double형의 data 배열 생성
	
	public Buffer(int size) {
		data=new double[size];
		System.out.println("New buffer");
		System.out.println(this+"\n");
	}//size를 인수로 받는 Buffer 생성자를 생성하고 data를 입력받은 정수 크기의 double 배열로 초기화
	
	public int getSize() {
		return data.length;
	}//data의 길이를 반환하는 getSize 메서드
	
	public synchronized void add(Producer p,double toAdd) throws InterruptedException{
		while(loc>=data.length) {
			System.out.println("Producer#"+p.getNum()+" @ Buffer is full.\n");
			wait();
		}//loc가 data의 길이보다 크거나 같으면(buffer가 가득차면) 출력문을 출력하고 thread를 blocked 상태로 바꿈
		System.out.println("Producer#"+p.getNum()+" Adding item on "+loc+": "+toAdd);
		data[loc++]=toAdd;//toAdd가 data 배열에 할당되고, loc값이 증가함
		System.out.println(this);
		System.out.flush();//버퍼링된 출력이 즉시 출력 스트림에 기록됨
		notifyAll();//wait 상태인 thread를 호출함
	}
	public synchronized double remove(Consumer c) throws InterruptedException{
		while(loc<=0) {
			System.out.println("Consumer#"+c.getNum()+"0 Buffer is empty.\n");
			wait();
		}//loc가 0보다 작으면(buffer가 비었으면) Buffer is empty를 출력하고 thread를 blocked 상태로 둠
		double hold=data[loc--];//loc를 data배열에 할당하고, loc값을 감소시킴
		System.out.println("Consumer#"+c.getNum()+" Removing item on "+loc+": "+hold);
		System.out.println(this);
		System.out.flush();//버퍼링된 출력이 즉시 출력 스트림에 기록됨
		return hold;//data 배열 반환
	}
	public synchronized String toString() {
		String toReturn="";
		for(double d:data) {
			toReturn+=String.format("%5.2f", d)+" ";
		}
		return toReturn;
	}//data 배열 내부의 element 개수만큼 반복문을 돌리면서 format의 형태로 element를 toReturn에 저장 후 반환
}
