/*
 * 3年　15組　96番　ゾウジファン
 * 出力：
 * Total number of points: 6
(2,1)
(-2,-1)
(0,2)
(-2,1)
(2,-1)
(0,-2)
 */

package javalec11;
import java.util.Set;
import java.util.HashSet;
import java.util.Objects;
class Point {
	private int x;
	private int y;
	public Point(int x, int y) { this.x = x; this.y = y; }
	public String toString() { return "(" + x + "," + y + ")"; }

	private Point rotate(int theta) {
		double rad = Math.toRadians(theta);
		int rx = (int) Math.round(x * Math.cos(rad) - y * Math.sin(rad));
		int ry = (int) Math.round(x * Math.sin(rad) + y * Math.cos(rad));
		return new Point(rx, ry);
	}
	public static Point testPoint(int i) {
		Point p = new Point(2, 1);
		return p.rotate(60*i);
	}
	@Override
	public boolean equals(Object obj) {
		if (this == obj) {
			return true;
		}
		if (obj == null || getClass() != obj.getClass()) {
			return false;
		}
		Point other = (Point) obj;
		return x == other.x && y == other.y;
	}
	public int hashCode() {
		return Objects.hash(x, y);
	}
}

public class PointTest {

	public static void main(String[] args) {
		// Point.testPoint()を1から10までの整数を引数として呼び出して得られる10個の点について、同じ座標を表すものがないか調べながら保存する。同じ座標のものが現れたらそれは無視する。
		// 重複を排除した後で、点の総数を表示し、次の行から点を1行に1つずつ(toString()使って)出力する。
		Set<Point> uniquePoints = new HashSet<>();

		for (int i = 1; i <= 10; i++) {
			Point point = Point.testPoint(i);
			uniquePoints.add(point);
		}

		System.out.println("Total number of points: " + uniquePoints.size());

		for (Point point : uniquePoints) {
			System.out.println(point.toString());
		}
	}

}
