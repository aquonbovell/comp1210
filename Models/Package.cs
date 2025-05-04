using System;

namespace comp1210.Models;

public class Package
{
  private string senderName = string.Empty;
  private string senderAddress = string.Empty;

  private string senderCity = string.Empty;

  private string senderState = string.Empty;
  private string senderZip = string.Empty;

  private string receiverName = string.Empty;
  private string receiverAddress = string.Empty;
  private string receiverCity = string.Empty;
  private string receiverState = string.Empty;
  private string receiverZip = string.Empty;

  private double weight = 0.0;

  private double cost = 0.0;
  public string SenderName
  {
    get { return senderName; }
    set { if (string.IsNullOrEmpty(value)) throw new ArgumentException("Sender name cannot be null or empty.", nameof(SenderName)); senderName = value; }
  }

  public string SenderAddress
  {
    get { return senderAddress; }
    set { if (string.IsNullOrEmpty(value)) throw new ArgumentException("Sender address cannot be null or empty.", nameof(SenderAddress)); senderAddress = value; }
  }

  public string SenderCity
  {
    get { return senderCity; }
    set { if (string.IsNullOrEmpty(value)) throw new ArgumentException("Sender city cannot be null or empty.", nameof(SenderCity)); senderCity = value; }
  }

  public string SenderState
  {
    get { return senderState; }
    set { if (string.IsNullOrEmpty(value)) throw new ArgumentException("Sender state cannot be null or empty.", nameof(SenderState)); senderState = value; }
  }

  public string SenderZip
  {
    get { return senderZip; }
    set { if (string.IsNullOrEmpty(value)) throw new ArgumentException("Sender zip cannot be null or empty.", nameof(SenderZip)); senderZip = value; }
  }

  public string ReceiverName
  {
    get { return receiverName; }
    set { if (string.IsNullOrEmpty(value)) throw new ArgumentException("Receiver name cannot be null or empty.", nameof(ReceiverName)); receiverName = value; }
  }

  public string ReceiverAddress
  {
    get { return receiverAddress; }
    set { if (string.IsNullOrEmpty(value)) throw new ArgumentException("Receiver address cannot be null or empty.", nameof(ReceiverAddress)); receiverAddress = value; }
  }

  public string ReceiverCity
  {
    get { return receiverCity; }
    set { if (string.IsNullOrEmpty(value)) throw new ArgumentException("Receiver city cannot be null or empty.", nameof(ReceiverCity)); receiverCity = value; }
  }

  public string ReceiverState
  {
    get { return receiverState; }
    set { if (string.IsNullOrEmpty(value)) throw new ArgumentException("Receiver state cannot be null or empty.", nameof(ReceiverState)); receiverState = value; }
  }

  public string ReceiverZip
  {
    get { return receiverZip; }
    set { if (string.IsNullOrEmpty(value)) throw new ArgumentException("Receiver zip cannot be null or empty.", nameof(ReceiverZip)); receiverZip = value; }
  }

  public double Weight
  {
    get { return weight; }
    set { if (value < 0) throw new ArgumentOutOfRangeException(nameof(Weight), "Weight cannot be negative."); weight = value; }
  }

  public double Cost
  {
    get { return cost; }
    set { if (value < 0) throw new ArgumentOutOfRangeException(nameof(Cost), "Cost cannot be negative."); cost = value; }
  }

  public double TotalCost
  {
    get { return Cost * Weight; }
  }

  public Package(string senderName, string senderAddress, string senderCity, string senderState, string senderZip,
                 string receiverName, string receiverAddress, string receiverCity, string receiverState, string receiverZip,
                 double weight, double cost)
  {
    SenderName = senderName;
    SenderAddress = senderAddress;
    SenderCity = senderCity;
    SenderState = senderState;
    SenderZip = senderZip;
    ReceiverName = receiverName;
    ReceiverAddress = receiverAddress;
    ReceiverCity = receiverCity;
    ReceiverState = receiverState;
    ReceiverZip = receiverZip;
    Weight = weight;
    Cost = cost;
  }

}
