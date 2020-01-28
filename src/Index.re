// Entry point

[@bs.val] external document: Js.t({..}) = "document";



// We're using raw DOM manipulations here, to avoid making you read
// ReasonReact when you might precisely be trying to learn it for the first
// time through the examples later.
let style = document##createElement("style");
document##head##appendChild(style);
style##innerHTML #= ExampleStyles.style;

let makeContainer = text => {
  let container = document##createElement("div");
  container##className #= "container";

  let title = document##createElement("div");
  title##className #= "containerTitle";
  title##innerText #= text;

  let content = document##createElement("div");
  content##className #= "containerContent";

  let () = container##appendChild(title);
  let () = container##appendChild(content);
  let () = document##body##appendChild(container);

  content;
};

let componentToDisplay = None;


ReactDOMRe.render(<Navigation/>, makeContainer("Navigation"));

/*<div>
      (switch componentToDisplay {
        | "Greeting" => ReactDOMRe.render(<Greeting />, makeContainer("Atomic Greeting"))
        | "BlinkingGreeting" => ReactDOMRe.render(<BlinkingGreeting> {React.string("Hello!")} </BlinkingGreeting>, makeContainer("Blinking Greeting"))
        | "ReducerFromReactJSDocs" => ReactDOMRe.render(<ReducerFromReactJSDocs />, makeContainer("Reducer From ReactJS Docs"),)
        | "FetchedDogPictures" => ReactDOMRe.render(<FetchedDogPictures />,makeContainer("Fetched Dog Pictures"))
        }
      )
</div>*/

/*{
  if(componentToDisplay != None){
    ReactDOMRe.render(componentToDisplay, makeContainer(React.string(componentToDisplay)));
  }
}*/


/*// All 4 examples.
ReactDOMRe.render(<Greeting />, makeContainer("Atomic Greeting"));

ReactDOMRe.render(
  <BlinkingGreeting> {React.string("Hello!")} </BlinkingGreeting>,
  makeContainer("Blinking Greeting"),
);

ReactDOMRe.render(
  <ReducerFromReactJSDocs />,
  makeContainer("Reducer From ReactJS Docs"),
);

ReactDOMRe.render(
  <FetchedDogPictures />,
  makeContainer("Fetched Dog Pictures"),
);

ReactDOMRe.render(<FetchRandomDog />, makeContainer("1 random Dog"));*/

