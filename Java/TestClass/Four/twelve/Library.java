package TestClass.Four.twelve;

import java.util.ArrayList;
import java.util.List;

interface Media {}
interface Book extends Media {}
interface Video extends Media {}
interface Newspaper extends Media {}

public class Library <T extends Media> {
    private List<T> resources = new ArrayList<T>();

    public void addMedia (T x) {
        resources.add(x);
    }

    public T retrievelLast () {
        int size = resources.size();
        if (size > 0) {
            return resources.get(size-1);
        }
        return null;
    }
}
