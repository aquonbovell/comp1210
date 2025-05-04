namespace comp1210.Models;

public class House
{
  private string address = string.Empty;
  private int numberOfRooms = 0;
  private double costPerFloor = 0.0;
  public string Address
  {
    get { return address; }
    set { if (string.IsNullOrEmpty(value)) throw new ArgumentException("Address cannot be null or empty.", nameof(Address)); address = value; }
  }

  public int NumberOfRooms
  {
    get { return numberOfRooms; }
    set { if (value < 0) throw new ArgumentOutOfRangeException(nameof(NumberOfRooms), "Number of rooms cannot be negative."); numberOfRooms = value; }
  }

  public double CostPerFloor
  {
    get { return costPerFloor; }
    set { if (value < 0) throw new ArgumentOutOfRangeException(nameof(CostPerFloor), "Cost per floor cannot be negative."); costPerFloor = value; }
  }

  public double TotalCost
  {
    get { return NumberOfRooms * CostPerFloor; }
  }

  public House(string address, int numberOfRooms, double costPerFloor)
  {
    Address = address;
    NumberOfRooms = numberOfRooms;
    CostPerFloor = costPerFloor;
  }
  public override string ToString()
  {
    return $"**********************************************\n" +
          $"Address: {Address}\n" +
          $"Number of Rooms: {NumberOfRooms}\n" +
          $"Cost per Floor: {CostPerFloor:C}\n" +
          $"Total Cost: {TotalCost:C}\n" +
          $"**********************************************\n";
  }
}
