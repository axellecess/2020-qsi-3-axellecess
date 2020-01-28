[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";

type route =
  | Greeting
  | BlinkingGreeting
  | ReducerFromReactJSDocs
  | FetchedDogPictures
  | FetchRandomDog
  | MyAccountGithub
  | EditAccountGithub;

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  let component = None;

  let listButtons = {
      <>
          <a href="/Greeting"><button> {React.string("Greeting")} </button></a> 
          <a href="/BlinkingGreeting"><button> {React.string("Blinking Greeting")} </button></a>
          <a href="/ReducerFromReactJSDocs"><button> {React.string("Reducer From ReactJS Docs")} </button></a>
          <a href="/FetchedDogPictures"><button> {React.string("Fetched Dog Pictures")} </button></a>
          <a href="/FetchRandomDog"><button> {React.string("Fetch Random Dog")} </button></a>
          <a href="/MyAccountGithub"><button> {React.string("My Account Github")} </button></a>
          <a href="/EditAccountGithub"><button> {React.string("Edit Account Github")} </button></a>
    </>
  };
    
<>
    <div
        style={ReactDOMRe.Style.make(
            ~alignItems="center",
            ~justifyContent="center",
            (),
        )}>
        {listButtons}
    </div>

    <div
      style={ReactDOMRe.Style.make(
        ~height="100%",
        ~width="100%",
        ~alignItems="center",
        ~justifyContent="center",
        ~paddingTop="50px",
        (),
      )}>
        {switch (url.path) {
        | ["Greeting"] => <Greeting />
        | ["BlinkingGreeting"] => <BlinkingGreeting>{React.string("Hello")}</ BlinkingGreeting>
        | ["ReducerFromReactJSDocs"] => <ReducerFromReactJSDocs />
        | ["FetchedDogPictures"] => <FetchedDogPictures/>
        | ["FetchRandomDog"] => <FetchRandomDog />
        | ["MyAccountGithub"] => <MyAccountGithub />
        | ["EditAccountGithub"] => <EditAccountGithub />
        | _ => <div>{React.string("ERROR 404")}</div>
        }}
    </div>
  </>;
}