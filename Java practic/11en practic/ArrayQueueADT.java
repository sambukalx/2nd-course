public class ArrayQueueADT {
    // I: size >= 0 && head >= 0 && i = 0..elements.length - 1 : a[i] != null
    private int size = 0;
    private int head = 0;
    private Object[] elements = new Object[5];

    // pre: element != null
    // post: queue.elements.length && queue.head = queue.head'
    // queue.size = queue.size' + 1 && i = 0..queue.elements.length - 1' : a[i]' = a[i] && a[(queue.head + queue.size) % queue.elements.length] = element
    public static void enqueue(ArrayQueueADT queue, Object element) {
        assert element != null;
        ensureCapacity(queue, queue.size + 1);
        queue.elements[(queue.head + queue.size) % queue.elements.length] = element;
        queue.size++;
    }

    // pre: capacity != null
    // post: queue.elements.length && i = 0..queue.elements.length - 1' : a[i]' = a[i]
    // a[queue.tail] = element
    private static void ensureCapacity(ArrayQueueADT queue, int capacity) {
        if (capacity <= queue.elements.length) {
            return;
        }
        Object[] newElements = new Object[2 * capacity];
        if (queue.head == 0) {
            for (int i = 0; i < queue.size; i++) {
                newElements[i] = queue.elements[i];
            }
            queue.elements = newElements;
        } else {
            for (int i = queue.head; i < queue.elements.length; i++) {
                newElements[i - queue.head] = queue.elements[i];
            }
            for (int i = 0; i <= (queue.head + queue.size) % queue.elements.length; i++) {
                newElements[i + queue.elements.length - queue.head] = queue.elements[i];
            }
            queue.head = 0;
            queue.elements = newElements;
        }
    }

    // pre: queue.head > 0
    // post: R = a[queue.head] && queue.head = (queue.head' + 1) % queue.elements.length
    // queue.size = queue.size' - 1 && i = 0..queue.elements.length - 1 : a[i]' = a[i]
    public static Object dequeue(ArrayQueueADT queue) {
        assert queue.size > 0;
        Object x = queue.elements[queue.head];
        queue.head = (queue.head + 1) % queue.elements.length;
        queue.size--;
        return x;
    }

    // pre: queue.head > 0
    // peek: R = a[queue.head] && queue.head = queue.head' && queue.size = queue.size'
    // i = 0..queue.elements.length - 1 : a[i]' = a[i]
    public static Object element(ArrayQueueADT queue) {
        assert queue.size > 0;
        return queue.elements[queue.head];
    }

    // post: R = queue.size && queue.size = queue.size' && queue.head = queue.head'
    // i = 0..queue.elements.length - 1 : a[i]' = a[i]
    public static int size(ArrayQueueADT queue) {
        return queue.size;
    }

    // post: R = queue.size > 0 && queue.size = queue.size' && queue.head = queue.head'
    // i = 0..queue.elements.length - 1 : a[i]' = a[i]
    public static boolean isEmpty(ArrayQueueADT queue) {
        return queue.size == 0;
    }

    // post: queue.head = 0 && queue.size = 0 && i = 0..queue.elements.length - 1 : a[i]' = null
    public static void clear(ArrayQueueADT queue) {
        Object[] newElements = new Object[5];
        queue.elements = newElements;
        queue.size = 0;
        queue.head = 0;
    }

    // post: R = String ans && queue.size = queue.size' && queue.head = queue.head'
    // i = 0..queue.elements.length - 1 : a[i]' = a[i]
    public static String toStr(ArrayQueueADT queue) {
        StringBuilder str = new StringBuilder("[");
        if (queue.size == 0) return "[]";
        if (queue.head < (queue.head + queue.size) % queue.elements.length) {
            for (int i = queue.head; i < (queue.head + queue.size) % queue.elements.length; i++) {
                str.append(queue.elements[i].toString());
                str.append(", ");
            }
        } else {
            for (int i = queue.head; i < queue.elements.length; i++) {
                str.append(queue.elements[i].toString());
                str.append(", ");
            }
            for (int i = 0; i < (queue.head + queue.size) % queue.elements.length; i++) {
                str.append(queue.elements[i].toString());
                str.append(", ");
            }
        }
        str.delete(str.length() - 2, str.length());
        str.insert(str.length(), ']');
        return str.toString();
    }
    public static void main(String[] args) {
        ArrayQueueADT queue = new ArrayQueueADT();

        //input
        for (int i = 0; i < 10; i++) {
            ArrayQueueADT.enqueue(queue, i);
        }
        System.out.println(ArrayQueueADT.toStr(queue));

        //pop half
        for (int i = 0; i < 5; i++) {
            ArrayQueueADT.dequeue(queue);
        }
        System.out.println(ArrayQueueADT.toStr(queue));

        //input half
        for (int i = 0; i < 5; i++) {
            ArrayQueueADT.enqueue(queue, i);
        }
        System.out.println(ArrayQueueADT.toStr(queue));

        //input more
        for (int i = 100; i < 108; i++) {
            ArrayQueueADT.enqueue(queue, i);
        }
        System.out.println(ArrayQueueADT.toStr(queue));
    }
}
