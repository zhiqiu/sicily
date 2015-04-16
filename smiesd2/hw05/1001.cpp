AutoReset::AutoReset(int *scoped_variable, int new_value)
{
    //*scoped_variable_=new_value;
    original_valu e = *scoped_variable;
    scoped_variable_ = scoped_variable;
    *scoped_variable = new_value;
}
AutoReset::~AutoReset()
{
    *scoped_variable_ = original_value;
}                                 
