package javalec6;
/*
 * 3年　15組　96番　ゾウジファン
 * 出力：
赤色の半径3の円
青色の上向きの三角形
 */
class Circle extends Figure{
	String color;
	int r;
	Circle(String color, int r) {
		this.color = color; this.r = r;
	}
	void showCircle() {
		System.out.println(color + "色の" + "半径" + r + "の円");
	}
}

class Triangle extends Figure{
	String color;
	String dir;
	Triangle(String color, String dir) {
		this.color = color; this.dir = dir;
	}
	void printTriangle() {
		System.out.println(color + "色の" + dir + "向きの三角形");
	}
}
class Figure {
	void printFig() {
		if (this instanceof Circle) {
			((Circle)this).showCircle();
		} else if (this instanceof Triangle) {
			((Triangle)this).printTriangle();
	}
}
}
public class FigureTest {

	public static void main(String[] args) {
		Figure[] flist = new Figure[2];
		flist[0] = new Circle("赤", 3);
		flist[1] = new Triangle("青", "上");
		
		for (Figure f : flist) {
			f.printFig();
		}

	}

}
