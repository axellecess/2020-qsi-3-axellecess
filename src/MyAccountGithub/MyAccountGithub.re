[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";

[@react.component]
let make = () => {
  
  let userData = () => {

    Js.Promise.(
      fetch("https://api.github.com/graphql")
      |> then_(response => response##json())
      |> then_(jsonResponse => {
           Js.log(jsonResponse);
           Js.Promise.resolve();
         })
      |> catch(_err => Js.Promise.resolve())
      |> ignore
    );
  };

  userData();

  <>
    <div
      style={ReactDOMRe.Style.make(
        ~height="100%",
        ~width="100%",
        ~alignItems="center",
        ~justifyContent="center",
        ~paddingTop="50px",
        (),
      )}>
      <div> <img /> </div>
      <div> {React.string("Nom : ")} </div>
      <div> {React.string("Status : ")} </div>
      <div> {React.string("Nombre de follower : ")} </div>
      <div> {React.string("Nnombre de following :")} </div>
    </div>
  </>;
};