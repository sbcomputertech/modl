# Minimal Object Description Language Spec

### Objects
Objects are defined like with a path in angled brackets, e.g. `<Modl/Core/Test>`.
You use this path to identify an object loaded from a modl file. 
This path should not be duplicated between objects.
Object declarations must be on their own line
It is recommended to have the path laid out in a way like:
- Your product name
- Where in the product this object is used
- A name for the object

Some examples would look like:
```
<Modl/Core/ModlMacro>
<TodoList/Objects/TodoItem>
<MyGameEngine/Sprites/Bullet>
```

### Parameters
A parameter is any value of an object.
All parameters are stored as strings, but parameter structures have methods to convert values' types.

### Comments
Comments in modl always take up one line.
There are no inline comments, or multiline comments.
All comments start with a dash `-` sign.
The dash cannot be indented.

Example:
```
- this is a comment
- [this : is a comment]
- <this/is/a/comment>
- this = is a comment
```

### Macros
- Macro definitions:
  - `[ macro name : macro value ]`
  - Spaces around the colon and brackets are ignored
  - Spaces in the name and value are allowed
  - Macro definitions must be on their own line
  - Macros can be used from anywhere in the same file
    - For example, even if you put a macro definition at the end of a file,
      you can still reference it from the top
- Macro usage:
  - `some param = (macro name)`
  - Any parameter value in parentheses will be interpreted as a macro definition
  - To use parentheses in a parameter, escape the parentheses like
    - `some param = -(not a macro)`