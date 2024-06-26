package javalec10;

class Chocolate {
	private int flavor;
	Chocolate(int f) { flavor = f; }
	public String toString() { return "C(" + flavor + ")"; }
	public void set_flavor(int f) { flavor = f; }
}

class Box {
	Chocolate piece[];
	Box(Chocolate[] c) {
		piece = c;
	}
	public String toString() {
		String ret = "";
		for (Chocolate c : piece) {
			ret += c.toString();
		}
		return ret;
	}
}

public class CloneTest {

	public static void main(String[] args) {
		Chocolate[] choco = {new Chocolate(0), new Chocolate(1), new Chocolate(2) };
		Box sample = new Box(choco);
		
		// boxには最初、sampleと同じチョコが入っているようにする（コピーする）
		Box box; //XXX
		
		// boxの0個目のチョコについて、味を9に変更
		//XXX
		
		// box, sampleを表示するとどうなるか？
		System.out.println(box);
		System.out.println(sample);
		
	}

}
