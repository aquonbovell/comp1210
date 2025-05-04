using System;

namespace comp1210.Models;

public class OvernightPackage : Package
{
  private double fee = 0.0;
  public double Fee
  {
    get { return fee; }
    set { if (value < 0) throw new ArgumentOutOfRangeException(nameof(fee), "Fee cannot be negative."); fee = value; }
  }

  public new double TotalCost
  {
    get { return (base.Cost + fee) * base.Weight; }
  }

  public OvernightPackage(string senderName, string senderAddress, string senderCity, string senderState, string senderZip,
                          string receiverName, string receiverAddress, string receiverCity, string receiverState, string receiverZip,
                          double weight, double cost, double fee) : base(senderName, senderAddress, senderCity, senderState, senderZip,
                                                                                   receiverName, receiverAddress, receiverCity, receiverState, receiverZip,
                                                                                   weight, cost)
  {
    Fee = fee;
  }

  public override string ToString()
  {
    return $"**********************************************\n" +
           $"Sender Name: {SenderName}\n" +
           $"Sender Address: {SenderAddress}\n" +
           $"Sender City: {SenderCity}\n" +
           $"Sender State: {SenderState}\n" +
           $"Sender Zip: {SenderZip}\n" +
           $"Receiver Name: {ReceiverName}\n" +
           $"Receiver Address: {ReceiverAddress}\n" +
           $"Receiver City: {ReceiverCity}\n" +
           $"Receiver State: {ReceiverState}\n" +
           $"Receiver Zip: {ReceiverZip}\n" +
           $"Weight: {Weight} lbs\n" +
           $"Cost: {Cost:C}\n" +
           $"**********************************************\n";
  }
}
