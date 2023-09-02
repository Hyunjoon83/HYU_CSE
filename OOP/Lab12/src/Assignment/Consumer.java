package Assignment;

public class Consumer extends Thread{
	private static int serial=0;
	private int pNum;
	private final Buffer buffer;//buffer를 final로 개체 생성 -> 한번 할당되면 다른 개체에 다시 할당할 수 없음
	
	public Consumer(Buffer buff) {
		this.pNum=serial++;
		this.buffer=buff;
	}//buffer를 인자로 받는 Consumer 생성자 생성, pNum은 serial번호를 1씩 증가하면서 받도록 설정
	public int getNum() {
		return pNum;
	}//pNUm을 반환하는 getNum 메서드 생성
	public void consume() throws InterruptedException{
		for(int i=buffer.getSize();i>0;i--) {
			System.out.println("Consumer#"+this.pNum+":"+this);
			buffer.remove(this);
		}
	}//buffer의 size만큼 반복해서 buffer에서 제거하고 출력문을 출력
	public void run() {
		try {
			consume();
		}//임의로 생성된 값을 buffer에서 제거
		catch(InterruptedException e) {
			e.printStackTrace();
		}//thread가 중단된 경우 예외 및 해당 위치에 대한 정보를 출력
	}
}
