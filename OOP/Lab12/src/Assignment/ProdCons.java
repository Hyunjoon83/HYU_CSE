package Assignment;

public class ProdCons {
	private Buffer buffer;
	private Producer[] producer;
	private Consumer[] consumer;
	
	public ProdCons() {
		Buffer buffer=new Buffer(5);
		
		producer=new Producer[2];
		consumer=new Consumer[2];
		
		for (int i = 0; i < producer.length; i++) {
			producer[i] = new Producer(buffer);
		}
		for (int i = 0; i < consumer.length; i++) {
			consumer[i] = new Consumer(buffer);
		}
	}
	private class Producer extends Thread{
		private final Buffer buffer;
		public Producer(Buffer buffer) {
			this.buffer=buffer;
		}
		public void produce() throws InterruptedException{
			for(int i=0;i<buffer.getSize();i++) {
				double value=Math.random();
				buffer.add(null,value);
			}
		}
		public void run() {
			try {
				produce();
			}catch(InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
	private class Consumer extends Thread{
		private final Buffer buffer;
		
		public Consumer(Buffer buffer) {
			this.buffer=buffer;
		}
		public void consume() throws InterruptedException{
			for(int i=0;i<buffer.getSize();i++) {
				buffer.remove(null);
			}
		}
		public void run() {
			try {
				consume();
			}catch(InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
	public void startThread() {
		for(Producer producer: producer) {
			producer.start();
		}
		for(Consumer consumer: consumer) {
			consumer.start();
		}
	}
}
