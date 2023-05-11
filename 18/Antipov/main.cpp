#include <iostream>

using namespace std;

// Структура для вузла списку
struct Node {
  int data;
  Node *next;
};

// Функція для додавання нового вузла в кінець списку
void push(Node **head_ref, int new_data) {
  Node *new_node = new Node;
  new_node->data = new_data;
  new_node->next = NULL;

  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }

  Node *last = *head_ref;
  while (last->next != NULL)
    last = last->next;

  last->next = new_node;
  return;
}

// Функція для знаходження суми парних елементів списку та видалення всіх парних
// елементів
int removeEvenNodes(Node **head_ref) {
  int sum = 0;
  Node *current = *head_ref;
  Node *prev = NULL;
  while (current != NULL) {
    if (current->data % 2 == 0) {
      sum += current->data;
      if (prev == NULL) {
        *head_ref = current->next;
      } else {
        prev->next = current->next;
      }
      Node *temp = current;
      current = current->next;
      delete temp;
    } else {
      prev = current;
      current = current->next;
    }
  }
  return sum;
}

// Функція для виведення списку на екран
void printList(Node *node) {
  while (node != NULL) {
    cout << node->data << " ";
    node = node->next;
  }
  cout << endl;
}

// Головна функція
int main() {
  Node *head = NULL;

  // Додавання елементів у список
  push(&head, 1);
  push(&head, 2);
  push(&head, 3);
  push(&head, 4);
  push(&head, 5);

  // Виведення списку на екран
  cout << "List before removing even nodes: ";
  printList(head);

  // Знаходження суми парних елементів та видалення всіх парних елементів зі
  // списку
  int sum = removeEvenNodes(&head);

  // Виведення списку на екран після видалення парних елементів
  cout << "List after removing even nodes: ";
  printList(head);

  // Виведення суми парних елементів на екран
  cout << "Sum of even nodes: " << sum << endl;

  return 0;
}