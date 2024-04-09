#include "truth_table.h"
#include "stack_object.h"
#include "logic.h"
//接受一个以‘\0’结尾的字符串
int truth_table_output(char *ex_string)
{
    char *iterator = ex_string;

    //抓取变元数量
    for(all_char = 0; iterator[all_char] != '\0'; ++all_char)
    {
        if(iterator[all_char] == left_ope) continue;
        if(iterator[all_char] == right_ope) continue;
        if(iterator[all_char] == and_ope) continue;
        if(iterator[all_char] == or_ope) continue;
        if(iterator[all_char] == not_ope) continue;
        if(iterator[all_char] == con_ope) continue;
        if(iterator[all_char] == same_or_ope) continue;
        ++index_val;
    }
    index_val--; //处理回车字符，fgets函数会读取回车
    all_char--;
    //抓取变元位置
    val_position = (void *)calloc(index_val,sizeof(int));

    for(int i = 0, j = 0; (iterator[i] != '\0') && (j < index_val);++i)
    {
        if(iterator[i] == left_ope) continue;
        if(iterator[i] == right_ope) continue;
        if(iterator[i] == and_ope) continue;
        if(iterator[i] == or_ope) continue;
        if(iterator[i] == not_ope) continue;
        if(iterator[i] == con_ope) continue;
        if(iterator[i] == same_or_ope) continue;
        val_position[j++] = i;
    }
    
    //只抓取不同的变量
    char *diff_char = (void *)calloc(index_val,sizeof(char));

    for(int i = 0, j = 0; (iterator[i] != '\0') && (j < index_val);++i)
    {
        if(iterator[i] == left_ope) continue;
        if(iterator[i] == right_ope) continue;
        if(iterator[i] == and_ope) continue;
        if(iterator[i] == or_ope) continue;
        if(iterator[i] == not_ope) continue;
        if(iterator[i] == con_ope) continue;
        if(iterator[i] == same_or_ope) continue;
        int k = 0;
        for( k = 0; diff_char[k] != '\0'; ++k)
        {
            if(diff_char[k] == iterator[i])
            {
                break;
            }
        }
        diff_char[k] = iterator[i];
    }

    int diff_char_number = 0;
    for (int k = 0 ; diff_char[k] != '\0' ; k++)
    {
        diff_char_number++;
    }
    diff_char_number--;

    //int diff_position[diff_char_number][index_val] = {0};
/*
    int **diff_position = (void *)calloc(diff_char_number,sizeof(int*));
    for (int i = 0 ;i < diff_char_number;i++)
    {
    *diff_position = (void *)calloc(index_val,sizeof(int));
    }
*/
    int** diff_position = (int**)malloc(diff_char_number * sizeof(int*));
    for (int i = 0; i < diff_char_number; i++) {
        diff_position[i] = (int*)malloc(index_val * sizeof(int));
    }
    for ( int i = 0;i < diff_char_number ;i++)
    {
        for(int j = 0; j<index_val;j++)
        {
            diff_position[i][j]=-1;
        }
    }

    for(int i = 0, j = 0; (iterator[i+1] != '\0') && (j < index_val);++i)
    {
        if(iterator[i] == left_ope) continue;
        if(iterator[i] == right_ope) continue;
        if(iterator[i] == and_ope) continue;
        if(iterator[i] == or_ope) continue;
        if(iterator[i] == not_ope) continue;
        if(iterator[i] == con_ope) continue;
        if(iterator[i] == same_or_ope) continue;
        int k = 0;
        for( k = 0; diff_char[k] != '\0'; ++k)
        {
            if(diff_char[k] == iterator[i])
            {
                int n = 0;
                for(n = 0;((diff_position[k][n] > -1) && (diff_position[k][n] < 20));n++)
                {
                    ;
                }
                diff_position[k][n] = i;
             //   printf("diffposition[k][n]%d",diff_position[k][n]);
            //   printf("diff_char[k];%c\t",diff_char[k]);
            }
        }
        
     //  printf("iterator[i]:%c",iterator[i]);
      // printf("ss\n");
    }


 //   printf("\n%s\n",diff_char);
  //  printf("%d\n",diff_char_number);
    /*
    for(int i = 0; diff_char[i] != '\0'; ++i)
    {
        for (int j = 0;diff_position[i][j] != 0;++j)
        {
            printf("%d\t",diff_position[i][j]);
        }
        printf("\n");
    }
    */
    //输出测试
    /*
    printf("number %d\n",index_val);
    printf("all number %d\n",all_char);
    for(int i = 0; i < index_val;++i)
    {
    printf("a:%d\t",val_position[i]);
    }
    printf("\n");
    */
    int all_call = pow(2, index_val);

    int index_call = 0;
//格式输出
printf("========================\n");
    int all_index = pow(2,diff_char_number);
    int in = 0;
    for(int i = 0; i<diff_char_number;++i)
    {
        printf("变元%d\t",i);
    }
    printf("值\n");

     for (int i = 0; i < diff_char_number; ++i)
        {
        printf("%c\t",diff_char[i]);
        }
    printf("\n");
    for(in = 0 ;in < all_index;++in)
    {
        int number[diff_char_number] ;
        for (int j = 0; j < diff_char_number; ++j)
        {
            number[j] = ((in >> j) & 1) + ascll_to_char;//转换为数值0或1
            for(int k = 0;(diff_position[j][k] > -1) && (diff_position[j][k] < 20); k++)
            {
                iterator[diff_position[j][k]] = number[j];
            }
        }

        //输出
        for (int i = 0; i < diff_char_number; ++i)
        {
            printf("%d\t",number[i]-48);
        }

        printf("%d\n",calculate(iterator));

    }
printf("======================\n");
/*
    for (int i = 0; i < index_val; ++i)
    {
        printf("变元%d\t",i);
    }
    printf("值");
    printf("\n");
    /*
    for(int i = 0; diff_char[i] != '\0' ; ++i)
    {
        int val_to_con = 
    }
    

    for (int i =0; i < all_call; ++i)
    {
        index_call = i;
        //将每一个变量换成常量
        for (int j = 0; j < index_val; ++j)
        {
            iterator[val_position[j]] = ((index_call >> j) & 1) + ascll_to_char;//转换为数值0或1
        }

        //输出测试

        for (int i = 0; i < index_val; ++i)
        {
        printf("%c\t",iterator[val_position[i]]);
        }

        printf("%d\n",calculate(iterator));

    }
    */

}

int calculate(char *ex_string)
{
    //创建两个堆栈，stack_a stack_b
    //操作数堆栈
    Node *stack_a = (void *)calloc(1, sizeof(Node));
    *stack_a = (void *)calloc(1, sizeof(node));
    //操作符堆栈
    Node *stack_b = (void *)calloc(1, sizeof(Node));
    *stack_b = (void *)calloc(1, sizeof(node));


    char *string = ex_string;
    for(int i = 0, j = 0; i < all_char; ++i)
    {
        Node tmp = (void *)calloc(1, sizeof(node));

        if (i == val_position[j])
        {
            tmp->val = string[i] - char_to_ascll;
            //number dont have rank
            push(stack_a,tmp);
      //      printf("\npush(stack_a,tmp):%d\n",tmp->val);
            ++j;
        }
        else
        {
            if (string[i] == left_ope)
            {
                tmp->val = 40;
                tmp->rank = rank7;
                push(stack_b, tmp);
            }
            else if(string[i] == not_ope)
            {
                tmp->val = 33;
                tmp->rank = rank6;
                Node tmp_number = (void *)calloc(1, sizeof(node));
                tmp_number->val = 1;
                push(stack_a, tmp_number);

                push(stack_b, tmp);
            }
            else if(string[i] == and_ope)
            {
                tmp->val = 38;
                tmp->rank = rank5;

                node top_node = top(stack_b);

         
                if((top_node.val==0) && (top_node.rank==0) && (top_node.next==0) )
                    push(stack_b,tmp);
                else if (top_node.val == 40)
                    push(stack_b, tmp);
                else if (top_node.rank < tmp->rank)
                    push(stack_b,tmp);
                else if (top_node.rank > tmp->rank)
                {

                    while(top_node.rank > tmp->rank)
                    {
                        if (top_node.val == 40)
                        {
                            break;
                        }
                        node pop_node = pop(stack_b);
                        node pop_number_1 = pop(stack_a);
                        node pop_number_2 = pop(stack_a);
                        if(pop_node.val == not_ope)
                        {
                            Node new_number = (void *)calloc(1, sizeof(node));
                            new_number->val = not_(pop_number_2.val, pop_number_1.val);
                            push(stack_a, new_number);
                        }
                        else if(pop_node.val == and_ope)
                        {
                            Node new_number = (void *)calloc(1, sizeof(node));
                            new_number->val = and_(pop_number_2.val, pop_number_1.val);
                            push(stack_a, new_number);
                        }
                        /*
                        else if(pop_node.val == same_or_ope)
                        {
                            Node new_number = (void *)calloc(1, sizeof(node));
                            new_number->val = same_or(pop_number_2.val, pop_number_1.val);
                            push(stack_a, new_number);
                        }
                        else if(pop_node.val == or_ope)
                        {
                            Node new_number = (void *)calloc(1, sizeof(node));
                            new_number->val = or_(pop_number_2.val, pop_number_1.val);
                            push(stack_a, new_number);
                        }
                        else if(pop_node.val == and_ope)
                        {
                            Node new_number = (void *)calloc(1, sizeof(node));
                            new_number->val = con_opr(pop_number_2.val, pop_number_1.val);
                            push(stack_a, new_number);
                        }
                        */
                        top_node = top(stack_b);
                    }
                    push(stack_b, tmp);
                }
            }
            else if(string[i] == same_or_ope)
            {
                 tmp->val = 36;
                tmp->rank = rank4;

                node top_node = top(stack_b);

         
                if((top_node.val==0) && (top_node.rank==0) && (top_node.next==0) )
                    push(stack_b,tmp);
                else if (top_node.val == 40)
                    push(stack_b, tmp);
                else if (top_node.rank < tmp->rank)
                    push(stack_b,tmp);
                else if (top_node.rank > tmp->rank)
                {

                    while(top_node.rank > tmp->rank)
                    {
                        if (top_node.val == 40)
                        {
                            break;
                        }
                        node pop_node = pop(stack_b);
                        node pop_number_1 = pop(stack_a);
                        node pop_number_2 = pop(stack_a);
                        if(pop_node.val == not_ope)
                        {
                            Node new_number = (void *)calloc(1, sizeof(node));
                            new_number->val = not_(pop_number_2.val, pop_number_1.val);
                            push(stack_a, new_number);
                        }
                         else if(pop_node.val == and_ope)
                        {
                            Node new_number = (void *)calloc(1, sizeof(node));
                            new_number->val = and_(pop_number_2.val, pop_number_1.val);
                            push(stack_a, new_number);
                        }
                        else if(pop_node.val == same_or_ope)
                        {
                            Node new_number = (void *)calloc(1, sizeof(node));
                            new_number->val = same_or(pop_number_2.val, pop_number_1.val);
                            push(stack_a, new_number);
                        }
                        top_node = top(stack_b);
                    }
                    push(stack_b, tmp);
                }
            }

            else if(string[i] == or_ope)
            {
                 tmp->val = 124;
                tmp->rank = rank3;

                node top_node = top(stack_b);

         
                if((top_node.val==0) && (top_node.rank==0) && (top_node.next==0) )
                    push(stack_b,tmp);
                else if (top_node.val == 40)
                    push(stack_b, tmp);
                else if (top_node.rank < tmp->rank)
                    push(stack_b,tmp);
                else if (top_node.rank > tmp->rank)
                {

                    while(top_node.rank > tmp->rank)
                    {
                        if (top_node.val == 40)
                        {
                            break;
                        }
                        node pop_node = pop(stack_b);
                        node pop_number_1 = pop(stack_a);
                        node pop_number_2 = pop(stack_a);
                        if(pop_node.val == not_ope)
                        {
                            Node new_number = (void *)calloc(1, sizeof(node));
                            new_number->val = not_(pop_number_2.val, pop_number_1.val);
                            push(stack_a, new_number);
                        }
                         else if(pop_node.val == and_ope)
                        {
                            Node new_number = (void *)calloc(1, sizeof(node));
                            new_number->val = and_(pop_number_2.val, pop_number_1.val);
                            push(stack_a, new_number);
                        }
                        else if(pop_node.val == same_or_ope)
                        {
                            Node new_number = (void *)calloc(1, sizeof(node));
                            new_number->val = same_or(pop_number_2.val, pop_number_1.val);
                            push(stack_a, new_number);
                        }
                        else if(pop_node.val == or_ope)
                        {
                            Node new_number = (void *)calloc(1, sizeof(node));
                            new_number->val = or_(pop_number_2.val, pop_number_1.val);
                            push(stack_a, new_number);
                        }
                        top_node = top(stack_b);
                    }
                    push(stack_b, tmp);
                }
            }
            else if(string[i] == con_ope)
            {
                 tmp->val = 62;
                tmp->rank = rank2;

                node top_node = top(stack_b);

         
                if((top_node.val==0) && (top_node.rank==0) && (top_node.next==0) )
                    push(stack_b,tmp);
                else if (top_node.val == 40)
                    push(stack_b, tmp);
                else if (top_node.rank < tmp->rank)
                    push(stack_b,tmp);
                else if (top_node.rank > tmp->rank)
                {

                    while(top_node.rank > tmp->rank)
                    {
                        if (top_node.val == 40)
                        {
                            break;
                        }
                        node pop_node = pop(stack_b);
                        node pop_number_1 = pop(stack_a);
                        node pop_number_2 = pop(stack_a);
                        if(pop_node.val == not_ope)
                        {
                            Node new_number = (void *)calloc(1, sizeof(node));
                            new_number->val = not_(pop_number_2.val, pop_number_1.val);
                            push(stack_a, new_number);
                        }
                         else if(pop_node.val == and_ope)
                        {
                            Node new_number = (void *)calloc(1, sizeof(node));
                            new_number->val = and_(pop_number_2.val, pop_number_1.val);
                            push(stack_a, new_number);
                        }
                        else if(pop_node.val == same_or_ope)
                        {
                            Node new_number = (void *)calloc(1, sizeof(node));
                            new_number->val = same_or(pop_number_2.val, pop_number_1.val);
                            push(stack_a, new_number);
                        }
                        else if(pop_node.val == or_ope)
                        {
                            Node new_number = (void *)calloc(1, sizeof(node));
                            new_number->val = or_(pop_number_2.val, pop_number_1.val);
                            push(stack_a, new_number);
                        }
                        else if(pop_node.val == con_ope)
                        {
                            Node new_number = (void *)calloc(1, sizeof(node));
                            new_number->val = con_opr(pop_number_2.val, pop_number_1.val);
                            push(stack_a, new_number);
                        }
                        top_node = top(stack_b);
                    }
                    push(stack_b, tmp);
                }
            }
            else if(string[i] == right_ope)
            {
                 tmp->val = 41;
                tmp->rank = rank1;

                node top_node = top(stack_b);
                    while(top_node.val != 40)
                    {
                        node pop_node = pop(stack_b);
                        node pop_number_1 = pop(stack_a);
                        node pop_number_2 = pop(stack_a);
                        if(pop_node.val == not_ope)
                        {
                            Node new_number = (void *)calloc(1, sizeof(node));
                            new_number->val = not_(pop_number_2.val, pop_number_1.val);
                            push(stack_a, new_number);
                        }
                         else if(pop_node.val == and_ope)
                        {
                            Node new_number = (void *)calloc(1, sizeof(node));
                            new_number->val = and_(pop_number_2.val, pop_number_1.val);
                            push(stack_a, new_number);
                        }
                        else if(pop_node.val == same_or_ope)
                        {
                            Node new_number = (void *)calloc(1, sizeof(node));
                            new_number->val = same_or(pop_number_2.val, pop_number_1.val);
                            push(stack_a, new_number);
                        }
                        else if(pop_node.val == or_ope)
                        {
                            Node new_number = (void *)calloc(1, sizeof(node));
                            new_number->val = or_(pop_number_2.val, pop_number_1.val);
                            push(stack_a, new_number);
                        }
                        else if(pop_node.val == con_ope)
                        {
                            Node new_number = (void *)calloc(1, sizeof(node));
                            new_number->val = con_opr(pop_number_2.val, pop_number_1.val);
                            push(stack_a, new_number);
                        }
                        top_node = top(stack_b);
                    }
                    pop(stack_b);
                    push(stack_b,tmp);
                    pop(stack_b);
                
            }
        }
    }
    node check = top(stack_b);
    if(check.val != 0)
    {
        while(check.val != 0)
        {
            node pop_node = pop(stack_b);
            node pop_number_1 = pop(stack_a);
            node pop_number_2 = pop(stack_a);
            if(pop_node.val == not_ope)
            {
                Node new_number = (void *)calloc(1, sizeof(node));
                new_number->val = not_(pop_number_2.val, pop_number_1.val);
                push(stack_a, new_number);
            }
            else if(pop_node.val == and_ope)
            {
                Node new_number = (void *)calloc(1, sizeof(node));
                new_number->val = and_(pop_number_2.val, pop_number_1.val);
                push(stack_a, new_number);
            }
            else if(pop_node.val == same_or_ope)
            {
                Node new_number = (void *)calloc(1, sizeof(node));
                new_number->val = same_or(pop_number_2.val, pop_number_1.val);
                push(stack_a, new_number);
            }
            else if(pop_node.val == or_ope)
            {
                Node new_number = (void *)calloc(1, sizeof(node));
                new_number->val = or_(pop_number_2.val, pop_number_1.val);
                push(stack_a, new_number);
            }
            else if(pop_node.val == con_ope)
            {
                Node new_number = (void *)calloc(1, sizeof(node));
                new_number->val = con_opr(pop_number_2.val, pop_number_1.val);
                push(stack_a, new_number);
            }
            check = top(stack_b);
        }
    }
    return (top(stack_a)).val;
}

int main()
{
    char buffer[100] = {0};
    printf("输入文本：");
    fgets(buffer, sizeof(buffer), stdin);
    truth_table_output(buffer);
}
