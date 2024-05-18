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
            internal VectorArray<T> data;
            internal Queue(int priority, T elem)
            {
                this.priority = priority;
                data = new VectorArray<T>();
                data.Put(elem);
            }
        }

        VectorArray<Queue<T>> queues;

        public PriorityQueue() 
        { 
            queues = new VectorArray<Queue<T>>();
        }

        public void Enqueue(int priority, T item)
        {
            for(int i = 0; i < queues.Size(); i++)
            {
                if (queues[i].priority == priority)
                {
                    queues[i].data.Put(item);
                    return;
                }
            }

            queues.Put(new Queue<T>(priority, item));
        }

        public T Dequeue() 
        {
            if(queues.IsEmpty())
            {
                throw new ArgumentOutOfRangeException();
            }

            Queue<T> queue = queues[0];
            int row = 0;
            for(int i = 0; i < queues.Size(); i++)
            {
                if (queues[i].priority < queue.priority)
                {
                    queue = queues[i];
                    row = i;
                }
            }
            var ret = queue.data[0];
            queue.data.Del(0);
            if(queue.data.Size() == 0)
            {
                queues.Del(row);
            }
            return ret;
        }

        public void Print()
        {
            for(int i = 0; i < queues.Size(); i++)
            {
                Console.Write("Priority: " + queues[i].priority);
                Console.Write(" Data: ");
                for (int j = 0; j < queues[i].data.Size(); j++)
                {
                    Console.Write($"{queues[i].data[j]} ");
                }
                Console.WriteLine();
            }
        }
    }
}
