package javalec2;

public class Sequence {
	public static void main(String[] args) {
		int[] points = {3, 5, 10, 11, 15};
		// ここに課題内容を実装する
		for (int i=0;i<points.length-1;i++) {
			Rectangle r = new Rectangle();
			r.w = points[i+1]-points[i];
			r.h = 2 * r.w;
			System.out.println(r.area());
		}
	}
}
