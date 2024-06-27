package javalec10;
/*
 * 3年　15組　96番　ゾウ　ジファン
 * 出力：
 * C(9)C(1)C(2)
	C(0)C(1)C(2)
 */
class Chocolate implements Cloneable{
	private int flavor;
	Chocolate(int f) { flavor = f; }
	public Chocolate clone() {
		return new Chocolate(flavor);
	}
	public String toString() { return "C(" + flavor + ")"; }
	public void set_flavor(int f) { flavor = f; }
}

class Box implements Cloneable{
	Chocolate piece[];
	Box(Chocolate[] c) {
		piece = c;
	}
	public Box clone() {
		Chocolate[] newpiece = new Chocolate[piece.length];
		for (int i = 0; i < piece.length; i++) {
			newpiece[i] = piece[i].clone();
		}
		return new Box(newpiece);
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
		Box box = sample.clone() ;
		box.piece[0].set_flavor(9);
		
		// box, sampleを表示するとどうなるか？
		System.out.println(box);
		System.out.println(sample);
		
	}

}
