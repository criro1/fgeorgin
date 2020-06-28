class list<E>
{
    E content;
    list<E> next;
    list<E> prev;

    list(E content, list<E> next, list<E> prev)
    {
        this.content = content;
        this.next = next;
        this.prev = prev;
    }

    // public void add(E content)
    // {
    //     list<String> head = new list<String>("Petr", null, null);
    // }

    public static void main(String[] args)
    {
        list<E> head = new list<E>("Petr", null, null);
        // head.add("Bob");
        System.out.println(head.content);
    }
}