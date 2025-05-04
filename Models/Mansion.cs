namespace comp1210.Models;

public class Mansion : House
{
  private int luxuryFee;
  public int LuxuryFee
  {
    get { return luxuryFee; }
    set { if (value < 0) throw new ArgumentOutOfRangeException(nameof(LuxuryFee), "Luxury fee cannot be negative."); luxuryFee = value; }
  }

  private int swimmingPools;
  public int SwimmingPools
  {
    get { return swimmingPools; }
    set { if (value < 0) throw new ArgumentOutOfRangeException(nameof(SwimmingPools), "Number of swimming pools cannot be negative."); swimmingPools = value; }
  }

  public new double TotalCost
  {
    get { return base.TotalCost + LuxuryFee + (SwimmingPools * 10000); }
  }

  public Mansion(string address, int numberOfRooms, double costPerFloor) : base(address, numberOfRooms, costPerFloor)
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
          $"Luxury Fee: {LuxuryFee:C}\n" +
          $"Number of Swimming Pools: {SwimmingPools}\n" +
          $"Total Cost: {TotalCost:C}\n" +
          $"**********************************************\n";
  }
}