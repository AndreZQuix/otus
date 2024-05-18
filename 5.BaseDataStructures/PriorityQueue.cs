using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _5.BaseDataStructures
{
    public class PriorityQueue<T>
    {
        internal class Queue<T>
        {
            internal int priority;
            internal List<T> data;
            internal Queue(int priority, T elem)
            {
                this.priority = priority;
                data = [elem];
            }
        }

        List<Queue<T>> queues;

        public PriorityQueue() 
        { 
            queues = [];
        }

        public void Enqueue(int priority, T item)
        {
            foreach(var q in queues)
            {
                if(q.priority == priority)
                {
                    q.data.Add(item);
                    return;
                }
            }

            queues.Add(new Queue<T>(priority, item));
        }

        public T Dequeue() 
        {
            Queue<T> queue = queues[0];
            foreach(var q in queues)
            {
                if (q.priority < queue.priority)
                    queue = q;
            }
            var ret = queue.data.First();
            queue.data.RemoveAt(0);
            if(queue.data.Count == 0)
            {
                queues.Remove(queue);
            }
            return ret;
        }

        public void Print()
        {
            foreach(var q in queues)
            {
                Console.Write("Priority: " + q.priority);
                Console.Write(" Data: ");
                foreach(var item in q.data)
                {
                    Console.Write($"{item} ");
                }
                Console.WriteLine();
            }
        }
    }
}
