package javalec12;

import java.util.List;
import java.util.ArrayList;


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
	}

	public static void main(String args[]) {
		OdakyuSort os = new OdakyuSort();

		os.printNeighbor("生田");
		System.out.println("----");
		os.printNeighbor("代々木上原");

	}
}
