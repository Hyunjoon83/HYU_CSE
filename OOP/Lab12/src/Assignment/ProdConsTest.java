package Assignment;

public class ProdConsTest {
	
	public static void main(String[] args) {
		Buffer buff=new Buffer(10);
		Producer prod=new Producer(buff);
		Consumer cons=new Consumer(buff);
		
		prod.start();
		cons.start();
	}//buffer, producer, consumer에 대한 객체를 생성한 뒤, thread를 시작함
}


/* <while을 if로 바꾸면 생기는 문제>
while 루프를 if 문으로 바꾸면 조건을 한 번만 검사한다는 의미여서, 특정 조건에서 참이 아니면 코드가 기다리지 않고 실행을 계속하기 때문에
thread가 다른 thread와 제대로 synchronization이 되지 않거나 일관성 없는 상태에서 공유 리소스에 액세스할 수 있는 잘못된 동작 또는 경합 상태가 발생할 수 있다
 */