package javalec12;
import java.util.Comparator;
import java.util.List;
import java.util.ArrayList;
/*
 * 3年　15組　96番　ゾウジファン
 * 出力：
 * 読売ランド前: 27849, 19.20
向ヶ丘遊園: 45891, 15.80
百合ヶ丘: 18510, 20.50
登戸: 131466, 15.20
和泉多摩川: 12314, 14.40
----
東北沢: 6298, 4.20
代々木八幡: 16841, 2.70
下北沢: 96539, 4.90
参宮橋: 9735, 1.50
世田谷代田: 7983, 5.60
 */

class Station {
	String name;
	int passengers;
	double pos;
	public Station(String[] arg) {
		name = arg[0];
		passengers = Integer.parseInt(arg[1]);
		pos = Double.parseDouble(arg[2]);
	}
	public String toString() {
		return String.format("%s: %d, %.2f", name, passengers, pos);
	}
}

public class OdakyuSort {
	static OdakyuData od = new OdakyuData();
	List<Station> stations;
	OdakyuSort() {
		stations = new ArrayList<Station>();
		for (int i = 0; i < od.numStations(); i++) {
			String[] stationstr = od.station(i);
			Station st = new Station(stationstr);
			stations.add(st);
		}
	}

	void printNeighbor(String sname) {
		// XXX
		Station targetStation = null;
		for (Station station : stations) {
			if (station.name.equals(sname)) {
				targetStation = station;
				break;
			}
		}

		if (targetStation != null) {
			final Station target = targetStation;
			stations.sort(Comparator.comparingDouble(station -> Math.abs(station.pos - target.pos)));
			int count = 0;
			for (Station station : stations) {
				if (!station.name.equals(sname)) {
					System.out.println(station);
					count++;
					if (count == 5) {
						break;
					}
				}
			}
		}
	}

	public static void main(String args[]) {
		OdakyuSort os = new OdakyuSort();

		os.printNeighbor("生田");
		System.out.println("----");
		os.printNeighbor("代々木上原");

	}
}
