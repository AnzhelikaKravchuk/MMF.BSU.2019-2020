<Query Kind="Program">
  <Namespace>System.Globalization</Namespace>
</Query>

void Main()
{
	Transformer transformer = new Transformer();
	Foo(transformer, new EnglishProvider());
}

//

public interface IDictionatyProvider
{
	Dictionary<char, string> Words { get; }

	Dictionary<double, string> SpecialCases { get; }
}

public class Transformer
{
	public string TransformToWords(double source, IDictionatyProvider provider)
	{
		bool value = provider.SpecialCases.TryGetValue(source, out string result);

		if (value) return result;

		string sourceString = source.ToString(CultureInfo.InvariantCulture);

		var sb = new StringBuilder();

		for (int i = 0; i < sourceString.Length; i++)
		{
			sb.Append(provider.Words[sourceString[i]] + (i < sourceString.Length - 1 ? " " : string.Empty));
		}

		return sb.ToString();
	}

}

public class EnglishProvider : IDictionatyProvider
{
	public Dictionary<char, string> Words =>
		new Dictionary<char, string>()
	{
		{ '0', "zero" },
		{ '1', "one" },
		{ '2', "two" },
		{ '3', "three" },
		{ '4', "four" },
		{ '5', "five" },
		{ '6', "six" },
		{ '7', "seven" },
		{ '8', "eight" },
		{ '9', "nine" },
		{ '.', "point" },
		{ '-', "minus" },
		{ '+', "plus" },
		{ 'E', "e" },
		{ 'e', "e" }
	};

	public Dictionary<double, string> SpecialCases =>
 		new Dictionary<double, string>()
	{
		{ double.NaN,  "not a number" },
		{ double.PositiveInfinity, "positive infinity" },
		{ double.NegativeInfinity,  "negative infinity" },
	};
}

public static void Foo(Transformer transformer, IDictionatyProvider provider)
{
	$"{double.NaN} -> {transformer.TransformToWords(double.NaN, provider)}".Dump();
	$"{-13.234400} -> {transformer.TransformToWords(-13.234400, provider)}".Dump();
	$"{double.PositiveInfinity} -> {transformer.TransformToWords(double.PositiveInfinity, provider)}".Dump();
}
