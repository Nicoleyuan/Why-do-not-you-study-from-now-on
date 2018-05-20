//TestContactIndexer.cs  索引器操纵对象离散的字段
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
namespace ClassApp.Ch04
{
  class Contact
  {
    private string name;
    // 一组联系方式信息           //索引参数串不分大小写
    private string mobile1;     //"M1"
    private string mobile2;     //"M2"
    private string homePhone;   //"HP"
    private string officePhone; //"OP"
    private string officeFax;   //"OF"
    public string Name
    {
      get
      {
        return name;
      }
      set
      {
        name = value;
      }
    }
    //以字符串代码作为参数的索引器
    public string this[string code]
    {
      get
      {
        switch (code.ToLower())  //或者.ToUpper()统一变成大写
        {
          case "m1":
            return mobile1;  //有return：不要break了
          case "m2":
            return mobile2;
          case "hp":
            return homePhone;
          case "op":
            return officePhone;
          case "of":
            return officeFax;
          default:
            return "N/A";
        }
      }
      set
      {
        switch (code.ToLower())
        {
          case "m1":
            mobile1 = value;
            break;
          case "m2":
            mobile2 = value;
            break;
          case "hp":
            homePhone = value;
            break;
          case "op":
            officePhone = value;
            break;
          case "of":
            officeFax = value;
            break;
          default:
            Console.WriteLine(
              "ERROR:您要设置的联系方式{0}不存在.", value);
            break;
        }
      }
    }
    public override string ToString()
    {
      string contact =
        string.Format("========{0}的联系方式========\n", name);
      contact += string.Format(
        "   手机1:{0}\n   手机2:{1}\n家庭电话:{2}\n",
        mobile1 ?? "N/A",  
        mobile2 ?? "N/A",
        homePhone ?? "N/A");
      // obj ?? value  : obj为null时，返回右侧的value; 否则返回obj
      contact += string.Format("办公电话:{0}\n公司传真:{1}\n",
        officePhone ?? "N/A",
        officeFax ?? "N/A");
      return contact;
    }
  }
  class TestContactIndexer
  {
    public static void Test()
    {
      Contact c1 = new Contact();
      c1.Name = "李四";
      c1["m1"] = "15888888888";
      c1["M2"] = "18111111111";
      //c1["hP"] = "15333333333";
      //c1["OP"] = "0514-87888888";
      c1["Of"] = "0514-86222222";
      c1["ddd"] = "0555-88888888";
      Console.WriteLine("{0}的公司传真是{1}.", c1.Name, c1["OF"]);
      Console.WriteLine(c1);
    }
  }
}
 
