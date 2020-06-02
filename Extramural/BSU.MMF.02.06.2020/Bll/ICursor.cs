namespace Bll
{
    public interface ICursor
    {
        int Start { get; }
        int End { get; }
        int Next { get; }
        void Reset();
    }
}